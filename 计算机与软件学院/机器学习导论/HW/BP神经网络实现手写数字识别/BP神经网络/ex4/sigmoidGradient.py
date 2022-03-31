#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
%SIGMOIDGRADIENT returns the gradient of the sigmoid function
%evaluated at z
%   g = SIGMOIDGRADIENT(z) computes the gradient of the sigmoid function
%   evaluated at z. This should work regardless if z is a matrix or a
%   vector. In particular, if z is a vector or matrix, you should return
%   the gradient for each element.
:Time:  2020/7/29 11:28
:Author:  lenjon
"""
import numpy as np

from sigmoid import sigmoid


def sigmoidGradient(z):
    g = np.zeros(z.shape)
    pass
    # ====================== YOUR CODE HERE ======================
    # You should change this


    # ========== END ==========
    return g
