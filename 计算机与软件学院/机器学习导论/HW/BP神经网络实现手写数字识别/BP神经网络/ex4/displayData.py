#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
不是作业
"""
import matplotlib.pyplot as plt
import numpy as np


def displayData(X, single=False):
    if single:
        fig, ax = plt.subplots(figsize=(1, 1))
        ax.matshow(X.reshape((20, 20)).T, cmap='gray_r')
        plt.xticks([])
        plt.yticks([])
        plt.show()
        return
    fig, ax_array = plt.subplots(nrows=10, ncols=10, sharex='all', sharey='all', figsize=(12, 12))
    for r in range(10):
        for c in range(10):
            ax_array[r, c].matshow(np.array(X[10 * r + c].reshape((20, 20))).T, cmap='gray_r')
    plt.xticks([])
    plt.yticks([])
