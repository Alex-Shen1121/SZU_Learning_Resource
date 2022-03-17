#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
:Time:  2020/7/27 18:50
:Author:  lenjon
"""

import numpy as np


def featureNormalize(X):
    """
    特征缩放
    :param X: 
    :return: 
    """
    # 你需要正确的返回变量X_norm，mu，sigma
    X_norm = X
    mu = np.zeros((1, X.shape[1]))
    sigma = np.zeros((1, X.shape[1]))
    pass
    # ================ YOUR CODE HERE ================
    # 1.计算X_norm的每一列的平均值，将平均值存储在mu中。
    # 2.计算X_norm的每一列的标准差，将平均值存储在sigma中。
    # 3.X_norm减去平均值再除以标准差得到最终的X_norm


    return X_norm, mu, sigma
