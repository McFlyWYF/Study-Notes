import numpy as np
import matplotlib.pyplot as plt

plt.rcParams['font.sans-serif'] = ['SimHei']  # 显示中文标签


def getPara(x, y):
    n = len(x) - 1  # 区间数
    A = np.zeros((n + 1, n + 2))  # 初始化(n+1,n+2)维初值为0的矩阵

    for i in range(1, n):
        A[i][i - 1] = 1 / (x[i] - x[i - 1])
        A[i][i] = 2 * (1 / (x[i] - x[i - 1]) + 1 / (x[i + 1] - x[i]))
        A[i][i + 1] = 1 / (x[i + 1] - x[i])
        A[i][n + 1] = 3 * ((y[i] - y[i - 1]) / ((x[i] - x[i - 1]) ** 2) + (y[i + 1] - y[i]) / ((x[i + 1] - x[i]) ** 2))

    A[0][0] = 2 / (x[1] - x[0])
    A[0][1] = 1 / (x[1] - x[0])
    print('1607094158-王宇飞')
    A[0][n + 1] = 3 * (y[1] - y[0]) / ((x[1] - x[0]) ** 2)

    A[n][n - 1] = 1 / (x[n] - x[n - 1])
    A[n][n] = 2 / (x[n] - x[n - 1])
    A[n][n + 1] = 3 * (y[n] - y[n - 1]) / ((x[n] - x[n - 1]) ** 2)

    k = np.linalg.solve(A[:, :n + 1], A[:, n + 1])
    return k


def compute(xx, x, y, k):
    i = 1
    while (x[i] < xx):
        i += 1
    z = (xx - x[i - 1]) / (x[i] - x[i - 1])
    a = k[i - 1] * (x[i] - x[i - 1]) - (y[i] - y[i - 1])
    b = -k[i] * (x[i] - x[i - 1]) + (y[i] - y[i - 1])
    c = (1 - z) * y[i - 1] + z * y[i] + z * (1 - z) * (a * (1 - z) + b * z)
    return c


if __name__ == '__main__':
    X = []
    Y = []

    x = [3, 4.5, 7, 9]
    y = [2.5, 1, 2.5, 0.5]

    k = getPara(x, y)
    print(k)
    for xx in np.arange(x[0], x[-1], 0.1):
        X.append(xx)
        Y.append(compute(xx, x, y, k))
        # print(X,Y)
    plt.scatter(x, y, c='r', label='离散点')

    plt.plot(X, Y, label='样条曲线')
    plt.legend(loc="upper left")

    plt.show()
