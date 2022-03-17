#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
这个也不是作业内容
"""

import numpy as np

from mapFeature import mapFeature
from plotData import plotData


def plotDecisionBoundary(theta, X, y):
    """
    绘制边界曲线
    :param X:
    :param y:
    :return: ax
    """
    theta = theta.reshape(1, -1)
    ax = plotData(X[:, 1:3], y)

    if theta.shape[1] <= 3:
        plotting_x = np.linspace(30, 100, 100)
        plotting_y = (-theta[0, 0] - theta[0, 1] * plotting_x) / theta[0, 2]
        ax.plot(plotting_x, plotting_y, 'y', label='Prediction', color='#18bfb5')
    else:
        u = np.linspace(-1, 1.5, 50)  # 想让图像更精确就把50改成大些（x
        v = np.linspace(-1, 1.5, 50)
        z = np.zeros((len(u), len(v)))
        for i in range(len(u)):
            for j in range(len(v)):
                z[i, j] = mapFeature(u[i], v[j]) @ theta.T
        ax.contour(u, v, z, 0, colors='#18bfb5')
    return ax
