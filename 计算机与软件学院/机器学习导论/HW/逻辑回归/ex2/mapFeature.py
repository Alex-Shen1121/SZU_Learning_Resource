#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
这个不是作业内容
:Time:  2020/7/28 14:16
:Author:  lenjon
"""

import numpy as np


def mapFeature(X1, X2):
    """
    根据两列生成新的特征值
    :param X1:
    :param X2:
    :return:
    """
    degree = 6  # 最高六次项
    out = np.ones(X1.shape).reshape(-1, 1)
    for i in range(1, degree + 1):
        for j in range(0, i + 1):
            out = np.insert(out, out.shape[1], np.power(X1, i - j) * np.power(X2, j), axis=1)
    return out
