import numpy as np
import math
import matplotlib.pyplot as plt
import time


def fun(x):
    f = math.pow(x, 3) - x - 1
    return f

start = time.time()

flag = True
list = []  # 存储b1
list_acc = []#存储误差

while (flag):
    a = float(input('请输入左端点值:'))
    b = float(input('请输入右端点值:'))
    accuracy = float(input('请输入精度:'))

    k = 0
    if fun(a) * fun(b) > 0:
        print('请重新输入！！！')

    else:
        b1 = b - fun(b) * (a - b) / (fun(a) - fun(b))#与x轴交点坐标
        while (flag):
            if fun(b1) == 0:
                print(b1)
                print('迭代次数为：',k)
            if fun(a) * fun(b1) < 0:
                b = b1
            else:
                a = b1
            least_b1 = b1
            list.append(b1)
            b1 = b - fun(b) * (a - b) / (fun(a) - fun(b))#b1坐标计算
            list_acc.append((b1 - least_b1) / b1)
            if abs((b1 - least_b1) / b1) < accuracy:
                print('零点坐标为:',b1)
                print('迭代次数为：',k)
                flag = False
            k = k + 1
end = time.time()
# print(list)
print('运行时间为:',end - start)

plt.subplot(121)
x = np.arange(-2, 3, 0.1)
y = x * x * x - x - 1
plt.plot(x, y)

plt.scatter(b1, 0, c='r')  # 绘制零点
plt.plot([-2, 3], [0, 0])  # 绘制y = 0直线
plt.plot([b1, b1], [-10, 0])  # 绘制x = b1的直线

plt.axis([-2, 3, -5, 10])
plt.title('试位法函数图')

# 每次与x的交点
for x in list:
    plt.scatter(x, 0, c='r')

#误差曲线
plt.subplot(122)
plt.plot(list_acc)
plt.show()
