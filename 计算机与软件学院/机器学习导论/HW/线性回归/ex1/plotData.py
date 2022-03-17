import matplotlib.pyplot as plt


def plotData(x, y):
    """
    绘制散点图
    :param x:  x
    :param y:  y
    :return: None
    """
    pass
    plt.scatter(x=x, y=y, c='red', marker='x')
    plt.xlabel('Population')
    plt.ylabel('Profit')
    plt.show()


