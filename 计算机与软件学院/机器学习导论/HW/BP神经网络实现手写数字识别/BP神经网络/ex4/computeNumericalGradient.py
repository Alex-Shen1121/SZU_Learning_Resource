#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
不是作业
"""
import numpy as np


def computeNumericalGradient(J, theta):
    """

    :param J: 是个函数
    :param theta:
    :return:
    """
    numgrad = np.zeros(theta.shape)
    e = 1e-4
    perturb = np.zeros(theta.shape)
    for p in range(theta.size):
        perturb[p] = e
        loss1, _ = J(theta - perturb)
        loss2, _ = J(theta + perturb)
        numgrad[p] = (loss2 - loss1) / (2 * e)
        perturb[p] = 0
    return numgrad

