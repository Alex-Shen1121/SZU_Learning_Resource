#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
生成测试权重矩阵
不是作业
:Time:  2020/7/29 12:43
:Author:  lenjon
"""

import numpy as np


def debugInitializeWeights(fan_out, fan_in):
    length = fan_out * (1 + fan_in)
    W = (np.sin(np.arange(1, length + 1)) / 10)
    W = np.reshape(W, (fan_out, 1 + fan_in), order='F')
    return W

