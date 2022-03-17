import numpy as np


def computeCost(X, y, theta):
    """
    计算代价函数
    :param X: 样本矩阵，行数为样本数量，列数为自变量
    :param y: 结果样本，行数为样本数量
    :param theta: 权重向量，行数为1
    :return: 该theta对应的代价
    """
    theta = theta.reshape(1, -1)
    m = X.shape[0]  # 样本数量m
    # 你需要正确的返回变量J
    J = 0
    pass
    # ================ YOUR CODE HERE ================
    #根据线性回归的代价函数公式编写代码
    # 提示：python中a@b表示a叉乘b


    return J