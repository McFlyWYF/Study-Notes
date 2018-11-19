import math
import matplotlib.pyplot as plt
import numpy as np
import time

plt.rcParams['font.sans-serif'] = ['SimHei']  # 用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False  # 用来正常显示负号


def fun(x):
    '''
    :param x:
    :return:
    函数f(x) = x^3 - x + 1
    '''

    f = math.pow(x, 3) - x - 1
    return f

def dichotomization():
    '''
    二分法计算零点
    :return:
    '''

    start = time.time()
    list = []  # 存储mid
    list_acc = []#存储误差
    flag = True
    while (flag):
        a = float(input('请输入左端点值:'))
        b = float(input('请输入右端点值:'))
        accuracy = float(input('请输入精度:'))

        k = 0
        if fun(a) * fun(b) > 0:
            print('请重新输入！！！')
        else:
            while (flag):
                if (fun(a) * fun(b) == 0.0):
                    if fun(a) == 0.0:  # 函数的最小值刚好是零点
                        print(a, k)
                        flag = False
                    else:
                        print(b)
                        print('迭代次数为：', k)

                        flag = False
                    break
                else:
                    mid = (a + b) / 2  # 找到二者的中点
                    list.append(mid)
                    list_acc.append(abs(b - a))
                    if abs(b - a) < accuracy:  # 满足最小精度值

                        print('零点坐标为:',mid)
                        print('迭代次数为：', k)

                        flag = False
                        break

                    else:
                        if fun(a) * fun(mid) > 0:
                            a = mid  # 中点值在零点左边
                        else:
                            b = mid  # 中点值在零点右边
                        k = k + 1  # 迭代次数
    end = time.time()
    print('运行时间为:',end - start)

    #函数曲线
    plt.subplot(211)
    x = np.arange(-2, 3, 0.1)
    y = x * x * x - x - 1
    y1 = 0
    plt.axis([-2, 3, -5, 10])
    plt.plot(x, y)
    plt.plot([-2, 3], [0, 0])
    plt.plot([mid, mid], [-10, 0])
    plt.title('函数曲线')
    plt.scatter(mid, 0, c='y')  # 零点

    for x in list:
        plt.scatter(x, 0, c='r')  # 每次迭代的点

    #误差曲线
    plt.subplot(212)
    plt.plot(list_acc)
    plt.title('loss曲线')
    plt.show()


if __name__ == '__main__':
    dichotomization()