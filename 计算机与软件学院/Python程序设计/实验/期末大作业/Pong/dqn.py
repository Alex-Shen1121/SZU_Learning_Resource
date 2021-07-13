import torch
import torch.optim as optim
import torch.nn.functional as F
import math
import random
import time
import datetime
import os
import argparse

from collections import namedtuple
from itertools import count
from env.wrappers import *
from env.memory import ReplayMemory
from env.models import *
from torch.utils.tensorboard import SummaryWriter

Transition = namedtuple('Transition',
                        ('state', 'action', 'next_state', 'reward'))
timeStr = datetime.datetime.strftime(
    datetime.datetime.now(), '%Y_%m_%d_%H_%M_%S')


def get_args():
    parser = argparse.ArgumentParser()
    parser.add_argument('--device', type=str,
                        default='cuda' if torch.cuda.is_available() else 'cpu')
    parser.add_argument('--batch-size', type=int, default=32)
    parser.add_argument('--seed', type=int, default=0)
    parser.add_argument('--gamma', type=float, default=0.99)
    parser.add_argument('--eps-start', type=float, default=0.8)
    parser.add_argument('--eps-end', type=float, default=0.02)
    parser.add_argument('--eps-decay', type=int, default=1000000)
    parser.add_argument('--target-update', type=int, default=1000)
    parser.add_argument('--lr', type=float, default=0.0001)
    parser.add_argument('--initial-memory', type=int, default=500)
    parser.add_argument('--train-episodes', type=int,
                        default=1600)  # 可以改成你想跑的总局数，比如1000、500
    parser.add_argument('--render-train', default=False,
                        action="store_true", help="Render the Training Process")
    parser.add_argument('--render-test', default=False,
                        action="store_true", help="Render the Testing Process")
    args = parser.parse_known_args()[0]
    args.memory_size = 200000

    args.a_path = 'bs'+str(args.batch_size)+'_epsS' + \
        str(args.eps_start)+'_'+timeStr
    args.path = './log/DQN/'+args.a_path
    os.makedirs(args.path)
    return args


def select_action(args, state):
    sample = random.random()
    eps_threshold = args.eps_end + (args.eps_start - args.eps_end) * \
        math.exp(-1. * args.steps_done / args.eps_decay)
    args.steps_done += 1

    if sample > eps_threshold:
        with torch.no_grad():
            return args.policy_net(state.to(args.device)).max(1)[1].view(1, 1)
    else:
        return torch.tensor([[random.randrange(4)]], device=args.device, dtype=torch.long)


def optimize_model(args):
    if len(args.memory) < args.batch_size:
        return
    transitions = args.memory.sample(args.batch_size)
    """
    zip(*transitions) unzips the transitions into
    Transition(*) creates new named tuple
    batch.state - tuple of all the states (each state is a tensor)
    batch.next_state - tuple of all the next states (each state is a tensor)
    batch.reward - tuple of all the rewards (each reward is a float)
    batch.action - tuple of all the actions (each action is an int)    
    """
    batch = Transition(*zip(*transitions))

    actions = tuple(
        (map(lambda a: torch.tensor([[a]], device=args.device), batch.action)))
    rewards = tuple(
        (map(lambda r: torch.tensor([r], device=args.device), batch.reward)))
    # s'为非空的标志，即空为False，非空为True
    non_final_mask = torch.tensor(
        tuple(map(lambda s: s is not None, batch.next_state)),
        device=args.device, dtype=torch.bool)
    # 取出batch中所有非空s'，因此数量可能小于batch_size
    non_final_next_states = torch.cat([s for s in batch.next_state
                                       if s is not None]).to(args.device)

    state_batch = torch.cat(batch.state).to(args.device)
    action_batch = torch.cat(actions)
    reward_batch = torch.cat(rewards)
    # Q网络预测的Q值
    state_action_values = args.policy_net(state_batch).gather(1, action_batch)

    """
    args.target_net(non_final_next_states)
        的shape为[batch_size,n_actions]，
        是一个batch下的batch_size个状态，每个状态对应的每个动作的V值
    args.target_net(non_final_next_states).max(1)
        的shape为[batch_size]，
        是一个batch下的batch_size个状态，每个状态的所有动作的Q值中最大的一个Q值
    max(1)返回(values,indices)，values为batch_size个最大Q值，indices为batch_size个对应的索引
    max(1)[0]即取出values，不取indices
    """
    # 一个batch的V(s')值，len为batch_size，初始化为全0，但之后可能len小于batch_size
    next_state_values = torch.zeros(args.batch_size, device=args.device)
    # non_final_mask为bool类型的list，len()将会减去mask中False的个数
    next_state_values[non_final_mask] = args.target_net(
        non_final_next_states).max(1)[0].detach()
    # 期望的实际Q值
    expected_state_action_values = (
        next_state_values * args.gamma) + reward_batch

    loss = F.smooth_l1_loss(state_action_values,
                            expected_state_action_values.unsqueeze(1))

    args.optimizer.zero_grad()
    loss.backward()
    for param in args.policy_net.parameters():
        param.grad.data.clamp_(-1, 1)
    args.optimizer.step()


def get_state(obs):
    state = np.array(obs)
    state = state.transpose((2, 0, 1))
    state = torch.from_numpy(state)
    return state.unsqueeze(0)


def train(args, env, n_episodes, render=True):
    render = True
    writer_path = os.path.join('pong_runs', 'dqn_' + args.a_path)
    writer = SummaryWriter(writer_path)
    episode_list = []
    reward_list = []
    for episode in range(n_episodes):
        obs = env.reset()
        state = get_state(obs)
        total_reward = 0.0
        for t in count():

            action = select_action(args, state)
            obs, reward, done, info = env.step(action)

            if render:
                env.render()

            total_reward += reward

            if not done:
                next_state = get_state(obs)
            else:
                next_state = None

            reward = torch.tensor([reward], device=args.device)

            args.memory.push(state, action.to('cpu'),
                             next_state, reward.to('cpu'))
            state = next_state

            if args.steps_done > args.initial_memory:
                optimize_model(args)
                if args.steps_done % args.target_update == 0:
                    args.target_net.load_state_dict(
                        args.policy_net.state_dict())

            if done:
                episode_list.append(episode)
                reward_list.append(total_reward)
                break

        # 写入tensorboard用于看图
        writer.add_scalar("reward", total_reward, episode)
        # 将每局对应的总奖励写成txt文件，用于matplotlib画图
        write_file(args.path+'/episodes.txt', episode_list)
        write_file(args.path+'/rewards.txt', reward_list)

        if episode % 10 == 0 or episode == n_episodes-1:
            print('Total steps: {} \t Episode/t: {}/{} \t Total reward: {}'.format(
                args.steps_done, episode, t, total_reward))
    env.close()
    return


def write_file(file_name, target):
    with open(file_name, "w") as file:
        for word in target:
            file.write(str(word))
            file.write('\n')


def pong_DQN(args=None):
    if args is None:
        args = get_args()

    # 创建Q网络和target_Q网络，n_actions默认为14，但Pong游戏用到6个动作，去除掉重复的2个动作
    policy_net = DQN(n_actions=4).to(args.device)
    target_net = DQN(n_actions=4).to(args.device)
    target_net.load_state_dict(policy_net.state_dict())
    optimizer = optim.Adam(policy_net.parameters(), lr=args.lr)
    steps_done = 0
    memory = ReplayMemory(args.memory_size)

    args.policy_net = policy_net
    args.target_net = target_net
    args.optimizer = optimizer
    args.steps_done = steps_done
    args.memory = memory

    env = gym.make("PongNoFrameskip-v4")
    env = make_env(env)
    np.random.seed(args.seed)
    torch.manual_seed(args.seed)
    env.seed(args.seed)

    train(args, env, args.train_episodes, render=args.render_train)
    print("=====\nTrain model finished.\n=====\n")


if __name__ == '__main__':
    pong_DQN(get_args())
