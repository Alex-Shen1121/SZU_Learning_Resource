from computeCost import computeCost
import numpy as np


def gradientDescent(X, y, theta, alpha, num_iters):
    """

    :param X: 样本矩阵，行数为样本数量，列数为自变量
    :param y: 结果样本，行数为样本数量
    :param theta: 权重初始向量，行数为1
    :param alpha: 学习速率
    :param num_iters: 迭代次数
    :return: 使代价局部最小的最优theta, 不同theta时对应的代价函数
    """
    theta = theta.reshape(1, -1)
    J_history = np.zeros(num_iters)
    m = X.shape[0]

    for i in range(num_iters):
        pass
        # ================ YOUR CODE HERE ================
        # 迭代更新theta，计算不同theta时对应的代价函数
        # 提示：在调试时，在这里打印成本函数（computeCost）和梯度的值非常有用。
        #利用梯度下降公式更新theta
        #利用computeCost函数计算J_history

    return theta, J_history
