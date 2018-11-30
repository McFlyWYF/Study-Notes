import matplotlib.pyplot as plt
import numpy as np
import random

plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False

fig = plt.figure()
ax = fig.add_subplot(111)

#生成直线上的各个点
x = np.arange(-5,5,0.1)
y = [5 * a + 3 for a in x]

# x = [1,2,3,4,5,6,7,8,9,10]
# y = [1,2,3,4,5,6,7,8,9,10]

#生成的各个点偏移一下，并放入到xa,ya中去
i=0
xa=[]
ya=[]
for xx in x:
    yy=y[i]
    d=float(random.randint(20,140)) / 100
    i+=1
    xa.append(xx * d)
    ya.append(yy * d)
x = xa
y = ya
ax.plot(xa,ya,color='m',linestyle='',marker='.')


def error(x, y):
    xy_sum = 0
    x_square_sum = 0
    for i in range(len(x)):
        xy = x[i] * y[i]
        xx = x[i] * x[i]

        xy_sum = xy_sum + xy
        x_square_sum = x_square_sum + xx

    x_y_sum = sum(x) * sum(y)

    x_sum_square = sum(x) ** 2

    x_average = sum(x) / len(x)
    y_average = sum(y) / len(y)

    return xy_sum, x_y_sum, x_square_sum, x_sum_square, x_average, y_average

def compute(xy_sum,x_y_sum,x_square_sum,x_sum_square,n,x_average,y_average):
    a1 = (n * xy_sum - x_y_sum) / (n * x_square_sum - x_sum_square)
    a0 = y_average - a1 * x_average
    return a0,a1


xy_sum,x_y_sum,x_square_sum,x_sum_square,x_average,y_average = error(x,y)
a0,a1 = compute(xy_sum,x_y_sum,x_square_sum,x_sum_square,len(x),x_average,y_average)
print('a0:',round(a0,2),'      ','a1:',round(a1))

plt.figure()
plt.scatter(x,y,c = 'r')
plt.xlim(-6,6)
plt.ylim(-30,30)
x = np.array(x)
y = a0 + a1 * x
plt.plot(x,y)
plt.title("最小二乘法线性拟合")
plt.show()