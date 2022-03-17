#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
% Instructions: Compute the cost of a particular choice of theta.
%               You should set J to the cost.
%               Compute the partial derivatives and set grad to the partial
%               derivatives of the cost w.r.t. each parameter in theta
:Time:  2020/7/28 14:41
:Author:  lenjon
"""
import numpy as np

from costFunction import costFunction


def costFunctionReg(theta, X, y, _lambda):
    theta = theta.reshape(1, -1)
    m = X.shape[0]
    J = 0
    grad = np.zeros(theta.shape)
    pass
    # ====================== YOUR CODE HERE ======================
    # You should change this

    # ========== END ==========
    return J, grad
