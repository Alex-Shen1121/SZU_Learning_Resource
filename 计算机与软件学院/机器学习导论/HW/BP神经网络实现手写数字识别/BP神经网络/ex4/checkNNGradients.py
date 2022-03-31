#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
检查神经网络
不是作业
"""
from computeNumericalGradient import computeNumericalGradient
from debugInitializeWeights import debugInitializeWeights
import numpy as np

from nnCostFunction import nnCostFunction


def checkNNGradients(_lambda=0):
    input_layer_size = 3
    hidden_layer_size = 5
    num_labels = 3
    m = 5
    Theta1 = debugInitializeWeights(hidden_layer_size, input_layer_size)
    Theta2 = debugInitializeWeights(num_labels, hidden_layer_size)
    X = debugInitializeWeights(m, input_layer_size - 1)
    y = np.array([[2 + i % num_labels for i in range(m)]]).T
    nn_params = np.append(Theta1.flatten(), Theta2.flatten())
    costFunc = lambda p: nnCostFunction(p, input_layer_size, hidden_layer_size, num_labels, X, y, _lambda)
    cost, grad = costFunc(nn_params)
    numgrad = computeNumericalGradient(costFunc, nn_params)
    a = numgrad.flatten()
    b = grad.flatten()
    print('The above two columns you get should be very similar.')
    print('(Left-Your Numerical Gradient, Right-Analytical Gradient)')
    print(np.concatenate((a.reshape(-1, 1), b.reshape(-1, 1)), axis=1))

    diff = np.linalg.norm(a - b) / np.linalg.norm(a + b)
    print("""
% Evaluate the norm of the difference between two solutions.  
% If you have a correct implementation, and assuming you used EPSILON = 0.0001 
% in computeNumericalGradient.m, then diff below should be less than 1e-9
""")
    print('diff:', diff)


if __name__ == '__main__':
    checkNNGradients()
