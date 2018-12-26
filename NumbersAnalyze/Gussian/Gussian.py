import numpy as np
import matplotlib.pyplot as plt

a = [[1, 2, -3],
     [0, 5, 2],
     [-2, 0, -3]]
b = np.array([[0, 8, -4, 2]])
b = b.T
b = b.astype('float')
print(b)

c = np.array([[0, 0, 0]])

d = [[0], [0], [0], [0]]
# A = np.hstack((a,b))
a = np.r_[c, a]
a = np.hstack((d, a))
a = a.astype('float')
print(a)
print()


# 交换主元
def exchange(a, b, n):
    max = a[1][1]
    j = 0
    for i in range(2, n):
        if abs(a[i][1]) > max:
            max = abs(a[i][1])
            j = i

    for k in range(1, n):
        temp = a[1][k]
        a[1][k] = a[j][k]
        a[j][k] = temp
    t = b[1][0]
    b[1][0] = b[j][0]
    b[j][0] = t

    return a, b


# 高斯消元
def Gusssian(a, b):
    if a[1][1] == 0:
        a, b = exchange(a, b, len(a))
    n = len(a) - 1
    x = [0, 0, 0, 0]
    f = 0
    sum = 0

    for k in range(1, n):
        for i in range(k + 1, n + 1):
            f = a[i][k] / a[k][k]
            for j in range(k + 1, n + 1):
                a[i][j] = a[i][j] - f * a[k][j]
            b[i] = b[i] - f * b[k]
    x[n] = b[n] / a[n][n]
    for i in range(n - 1, 0, -1):
        sum = b[i]
        for j in range(i + 1, n + 1):
            sum = sum - a[i][j] * x[j]
        x[i] = sum / a[i][i]

    return x


x = Gusssian(a, b)
for i in range(0, len(x)):
    print('x[', i, ']=', x[i])

