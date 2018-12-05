import numpy as np
import matplotlib.pylab as plt

x = [0,1,2,4]
y = [3,6,11,51]


def Newton(x, y):
    w = np.zeros([len(x), len(x) + 1])
    w[:, 0] = x
    w[:, 1] = y
    print('1607094158-王宇飞')
    for i in range(w.shape[1] - 2):
        for j in range(i, w.shape[0] - 1):
            w[j + 1, i + 2] = (w[j + 1, i + 1] - w[j, i + 1]) / (w[j + 1, 0] - w[j - i, 0])

    def f(a):
        r = w[0, 1]
        c = 1
        for i in range(1, w.shape[0]):
            b = w[i, i + 1]
            c *= (a - x[i - 1])
            r += b * c
        return r

    return f


f = Newton(x, y)
plt.scatter(x, y)
x = np.arange(0, 8, 0.1)
plt.plot(x, f(x))

plt.scatter(0.5,f(0.5),c = 'r')
print(f(0.5))

plt.show()