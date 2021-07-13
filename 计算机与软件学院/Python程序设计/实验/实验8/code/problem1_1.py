import numpy as np
import math

mysqrt = [math.sqrt(x) for x in range(0, 5)]
mycrt = [x**(1/3) for x in range(0, 5)]

npData = np.array(mysqrt)
print("The shape:", npData.shape)
print("The dimensionality:", npData.ndim)
print("The type:", npData.dtype)

twoDarray = np.array([mysqrt, mycrt])
print("The shape:", twoDarray.shape)
print("The dimensionality:", twoDarray.ndim)
print("The type:", twoDarray.dtype)
