import matplotlib.pyplot as plt
import numpy as np

plt.rcParams['font.sans-serif'] = ['SimHei']  # 用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False  # 用来正常显示负号



def f(x):
    return np.power(x,5) - 3.5 * np.power(x,4) + 2.75 * np.power(x,3) + 2.125 * np.power(x,2)- 3.875 * x + 1.25

a = [1,-3.5,2.75,2.125,-3.875,1.25]


def compute(a, r=-1, s=-1):
    r_list = []
    s_list = []
    flag = True
    k = 1
    while flag:

        b = []
        for i, v in enumerate(a):
            if i == 0:
                b.append(v)
            elif i == 1:
                b.append(v + r * b[-1])
            else:
                b.append(v + r * b[-1] + s * b[-2])

        b0 = b[-1]
        b1 = b[-2]
        c = []
        for i, v in enumerate(b):
            if i == 0:
                c.append(v)
            elif i == 1:
                c.append(v + r * c[-1])
            else:
                c.append(v + r * c[-1] + s * c[-2])

        c1 = c[-2]
        c2 = c[-3]
        c3 = c[-4]
        dr = (c3 * b0 - c2 * b1) / (c2 * c2 - c1 * c3)
        ds = (c2 * b0 - c1 * b1) / (c1 * c3 - c2 * c2)

        if (abs(dr / r) < 0.01) and (abs(ds / s) < 0.01):
            flag = False
        else:
            k = k + 1
        r = r + dr
        s = s + ds
        r_list.append(r)
        s_list.append(s)
    return ((r + (r ** 2 + 4 * s) ** (1 / 2)) / 2, (r - (r ** 2 + 4 * s) ** (1 / 2)) / 2, a, b, r_list, s_list, k)


def Berstow(a):
    # 阶数为5阶
    x1, x2, a, b, r_list, s_list, k = compute(a)
    print('x1 = %.2f   x2 = %.2f' % (x1, x2))
    print('迭代次数为：', k)

    plt.figure()
    x = np.arange(-3, 5, 0.1)
    plt.plot(x, f(x))
    plt.axis([-2, 3, -3, 4])
    plt.hlines(0, plt.xlim()[0], plt.xlim()[1])
    plt.scatter([x1, x2], [0, 0], c='r')
    plt.title('两个不相等的实数根')
    plt.show()

    # 阶数为3阶
    a[5] = b[3]
    a[4] = b[2]
    a[3] = b[1]
    a[2] = b[0]
    a[1] = 0
    a[0] = 0
    r = r_list[-1]
    s = s_list[-1]
    x3, x4, a, b, r_list, s_list, k = compute(a, r, s)
    print('x3 = ', x3, 'x4 = ', x4)
    print('迭代次数为：', k)

    plt.figure()
    x = np.arange(-3, 5, 0.1)
    plt.plot(x, f(x))
    plt.axis([-2, 3, -3, 4])
    plt.hlines(0, plt.xlim()[0], plt.xlim()[1])
    plt.scatter([x3, x4], [0, 0], c='r')
    plt.title('两个互为相反的复根')
    plt.show()

    # 阶数为1阶
    r = r_list[-1]
    s = s_list[-1]
    x5 = round(-(r / s), 0)
    print('x5 = ', x5)

    plt.figure()
    x = np.arange(-3, 5, 0.1)
    plt.plot(x, f(x))
    plt.axis([-2, 3, -3, 4])
    plt.hlines(0, plt.xlim()[0], plt.xlim()[1])
    plt.scatter(x5, 0, c='r')
    plt.title('单根')
    plt.show()

if __name__ == '__main__':
    Berstow(a)