import numpy as np
import matplotlib.pyplot as plt

plt.rcParams['font.sans-serif'] = ['SimHei']  # 用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False  # 用来正常显示负号

def f(x):
    return np.power(x,3) - x - 1

def f1(x):
    return 3 * np.power(x,2) - 1


def Newton(xstart):
    flag = True
    k = 1
    list_xstart = []  # 存储每次开始的x值
    list_new = []  # 存储每次迭代之后的新值
    list_loss = []  # 存储loss
    list_f = []  # 存储该点的函数值

    while flag:
        xi = xstart
        xii = xi - f(xi) / f1(xi)
        list_xstart.append(xi)
        list_loss.append(abs(xii - xi) / xii)
        list_f.append(f(xi))
        if (abs(xii - xi) / xii) < 0.0001:
            print('零点值是：%.5f' % xi)
            print('迭代次数是：', k)
            flag = False
        else:
            xstart = xii
            list_new.append(xii)
            k = k + 1

    plt.subplot(211)
    x = np.arange(0, 3, 0.1)
    y = np.power(x, 3) - x - 1
    plt.plot(x, y)
    plt.axis([0, 3, -10, 20])
    for i in range(len(list_xstart)):
        plt.scatter(list_xstart[i], 0, c='r')

    for i in range(len(list_new)):
        plt.plot([list_xstart[i], list_new[i]], [list_f[i], 0], c='r')

    plt.plot([-3, 3], [0, 0])
    plt.title('Newton函数图')

    plt.subplot(212)
    plt.plot(list_loss)
    plt.title('loss曲线')
    plt.show()

if __name__ == '__main__':
    Newton(2)