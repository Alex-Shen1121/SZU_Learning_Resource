#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
% Instructions: Compute the cost of a particular choice of theta.
%               You should set J to the cost.
%               Compute the partial derivatives and set grad to the partial
%               derivatives of the cost w.r.t. each parameter in theta
"""
import numpy as np

from sigmoid import sigmoid


def costFunction(theta, X, y):
    # Initialize
    theta = theta.reshape(1, -1)
    m = X.shape[0]
    J = 0
    grad = np.zeros(theta.shape)
    pass
    # ====================== YOUR CODE HERE ======================
    # You should change this


    # ========== END ==========
    return J, grad
