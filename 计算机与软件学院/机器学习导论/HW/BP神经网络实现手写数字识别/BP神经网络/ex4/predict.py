#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
不是作业
:Time:  2020/7/29 19:13
:Author:  lenjon
"""

import numpy as np

from sigmoid import sigmoid


def predict(Theta1, Theta2, X):
    if len(X.shape) == 1:
        X = X.reshape(1, -1)
    m = X.shape[0]
    z2 = np.insert(X, 0, np.ones(m), axis=1) @ Theta1.T
    a2 = sigmoid(z2)
    z3 = np.insert(a2, 0, values=np.ones(a2.shape[0]), axis=1) @ Theta2.T
    a3 = sigmoid(z3)
    p = (np.argmax(a3, axis=1) + 1).reshape(-1, 1)
    return p
