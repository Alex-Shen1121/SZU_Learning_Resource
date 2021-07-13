import numpy as np

zeros = np.zeros(3)
zMat = np.zeros((4, 3))
ones = np.ones(3)
oMat = np.ones((3, 2))
diag = np.eye(4)
rng = np.arange(5)
dm = np.diag(rng)
print(dm.shape)
zMat_re = zMat.reshape(6, 2)
