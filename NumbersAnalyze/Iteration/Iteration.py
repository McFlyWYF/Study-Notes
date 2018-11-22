import numpy as np
import matplotlib.pyplot as plt

plt.rcParams['font.sans-serif'] = ['SimHei']  # 用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False  # 用来正常显示负号


def f(x):
    '''
    function:f = (x + 1)^(1/3)
    :param x:
    :return:
    '''
    return np.power(x + 1, 1 / 3)


def iteration(xstart):
    '''
    :param xstart:
    :return:
    '''

    flag = True
    k = 1
    list_xstart = []
    list_f = []
    list_loss = []

    while flag:
        xi = f(xstart)
        list_xstart.append(xstart)
        list_f.append(xi)
        list_loss.append(abs((xi - xstart) / xstart))
        if abs((xi - xstart) / xstart) < 0.0001:
            print('方程零点是：%.5f' % xi)
            print('迭代次数是：', k)
            flag = False

        else:
            xstart = f(xstart)
            k = k + 1

    plt.subplot(211)
    x = np.arange(-1, 3, 0.1)
    y = np.power(x + 1, 1 / 3)

    plt.plot(x, x)
    plt.plot(x, y)
    i = 0
    for i in range(len(list_xstart)):
        plt.plot([list_xstart[i], list_xstart[i]], [list_xstart[i], list_f[i]], c='r')
        i = i + 1
    plt.scatter(xi, f(xi), c='g')  # 零点
    plt.title('Sample Point Iteration函数图')

    plt.subplot(212)
    plt.plot(list_loss)
    plt.title('loss曲线')
    plt.show()


if __name__ == '__main__':
    iteration(2)