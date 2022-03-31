#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
不是作业
"""
import numpy as np


def sigmoid(z):
    return 1 / (1 + np.exp(-z))
