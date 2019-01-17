import numpy as np
import matplotlib.pyplot as plt


# 原函数
def F(x, y):
    return (2 * x + 1) ** 0.5


# 斜率公式
def f(x, y):
    return y - 2 * x / y


# 步长0.01,x=0时,y=1
def compute(x, y, h):
    Y = []
    acc = []
    print('1607094158-王宇飞')
    for i in range(0, 11):
        y0_new = round(y + h * f(x, y), 4)
        y1_new = round(y + h * f(x + h, y0_new), 4)
        y_true = round(F(x, y), 4)
        y_acc = round(y_true - y, 4)
        print(i, x, y, y_true, y_acc, sep='\t\t')
        Y.append(y)
        acc.append(y_acc)
        y = round((y1_new + y1_new) / 2, 4)
        x = round(x + h, 4)
    return Y, acc


Y, acc = compute(0, 1, 0.01)
print(Y)
x = np.arange(0, 10, 0.1)
y = (2 * x + 1) ** 0.5
plt.plot(x, y, c='r')
plt.show()
