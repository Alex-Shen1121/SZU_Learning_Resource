# 《Python Programming》Final Report
 ## Game AI training based on RL and DRL

### Project maintainer
+ Shen Chenyu 	2019092121@email.szu.edu.cn
+ Dong Yunhao	 2019284073@email.szu.edu.cn
+ Xiao Youqi	 	 2019151099@email.szu.edu.cn

### Introduction
Reinforcement learning is a branch of machine learning. Compared with the classic supervised and unsupervised learning problems of machine learning, the biggest feature of reinforcement learning is learning in interaction. In the interaction with the environment, the agent continuously learns knowledge based on the rewards or punishments obtained, and is more adapted to the environment. RL and DRL are two algorithm of Game AI training method. This project uses two examples to show the RL and DRL algorithm. In the first demo RL algorithm is used to train to find way in a maze and in another demo DRL algorithm is used to train our block to reflect ball backwards.



### Project 1 --- Maze

1. This programme is running under numpy. Install numpy using:
```bash
pip install numpy
```

2. Enter programme path 

```bash
cd ...\Q-learning\
```

3. Run Q-learning
```bash
Python q_learning_agent.py
```

### Project 2 --- Pong

- To use GPU, CUDA and cuDNN should be installed correctly.

  *How to install?* 

  + [CUDA](https://docs.nvidia.com/cuda/cuda-quick-start-guide/index.html)
  + [cuDNN](https://docs.nvidia.com/deeplearning/sdk/cudnn-install/)


1. Install the requirements using:  

   ```bash 
   pip install gym
   conda install pytorch torchvision torchaudio cudatoolkit=11.1 -c pytorch -c conda-forge
   pip install opencv-python
   pip install tensorboard
   pip install gym[atari]
   ```

2. Run the DQN. 

   ```bash 
   python pong_DQN.py
   ```

3. If you need to check training result based on tensorboard. Using:  
   `tensorboard --logdir <path> ` 

   eg. tensorboard --logdir I:\大二下\Python程序设计\Pong_Maze_byDRL\Pong_for_demo\pong_runs\dqn_bs32_epsS0.8_2021_07_01_01_42_46

#### TODO  

The hyperparameters may not be the best for Pong game in DQN. It still needs more explorations.

#### References

[1] Haodi Zhang, Zihang Gao, Yi Zhou, et al. Faster and Safer Training by Embedding High-Level Knowledge into Deep Reinforcement Learning. arXiv preprint. 2019:1910.09986.  

[2] Mnih V., Kavukcuoglu K., Silver D., et al. Human-level control through deep reinforcement learning. Nature,2015,518(7540):529-533.

[3] Mnih, Volodymyr, et al. "Playing atari with deep reinforcement learning." *arXiv preprint arXiv:1312.5602* (2013).

