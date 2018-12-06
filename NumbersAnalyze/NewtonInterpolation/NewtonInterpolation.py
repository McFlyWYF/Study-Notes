import numpy as np
import matplotlib.pylab as plt

plt.rcParams['font.sans-serif'] = ['SimHei']  # 用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False  # 用来正常显示负号

x = [0, 1, 2, 4]
y = [3, 6, 11, 51]


def NewtonInter(x, y):
    a = np.zeros([len(x), len(x) + 1])

    a[:, 0] = x
    a[:, 1] = y

    print('1607094158-王宇飞')

    for i in range(1, len(x)):
        for j in range(i, len(x)):
            a[j, i + 1] = (a[j, i] - a[j - 1, i]) / (a[j, 0] - a[j - i, 0])  # 差商计算公式
    print('差商表')
    print(a)

    return a


a = NewtonInter(x, y)

bb = []
for i in range(0, len(x)):
    bb.append(a[i, i + 1])
print('系数', bb)


def f(x0):
    c = 1
    d = a[0, 1]

    for i in range(1, len(x)):
        b = a[i, i + 1]
        c = c * (x0 - x[i - 1])
        d = d + b * c
    return d


plt.scatter(x, y, c='b')

x_points = np.arange(0, 5, 0.1)
y_points = []
for i in range(len(x_points)):
    y_points.append(round(f(x_points[i]), 2))
plt.plot(x_points, y_points, label='拟合曲线')

plt.scatter(0.5, f(0.5), label='预测点', c='r')  # x = 0.5
print(f(0.5))
plt.title('牛顿插值法')
plt.legend(loc="upper left")
plt.show()
