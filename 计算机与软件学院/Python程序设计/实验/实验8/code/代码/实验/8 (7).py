import numpy as np
import matplotlib.pyplot as plt
from PIL import Image
from numpy.core.fromnumeric import amax
from numpy.lib.type_check import imag

image = Image.open("picture.jpg")
image = np.array(image)
# print(image.shape)
# plt.imshow(image)
# plt.axis('off')
# plt.show()

# # 上下翻转
# image2=image[::-1,:,:]
# plt.imshow(image2)
# plt.axis('off')
# plt.show()


# # 图片变亮
# image3 = np.clip(image*1.5,a_min=0.,a_max=255.)
# plt.imshow(image3.astype('uint8'))
# plt.axis('off')
# plt.show()

# B_img = image.copy()
# B_img[:, :, [0, 1]] = 0
# R_img = image.copy()
# R_img[:, :, [0, 2]] = 0
# G_img = image.copy()
# G_img[:, :, [2, 1]] = 0
# fig, ax = plt.subplots(2, 2)
# ax[0, 0].imshow(image)
# ax[1, 1].imshow(R_img)
# ax[1, 0].imshow(G_img)
# ax[0, 1].imshow(B_img)
# fig.set_size_inches(8, 8)
# plt.tight_layout()
# plt.axis('off')
# plt.show()

# # 添加mask
# k = np.random.randint(0, 256, size=(200, 200, 3), dtype=np.uint8)
# test = image.copy()
# test[300:500, 400:600] = k
# plt.imshow(test)
# plt.axis('off')
# plt.show()

# # 交换通道
# t = image.copy()
# plt.imshow(t[:, :, [2, 1,0]])
# plt.show()
