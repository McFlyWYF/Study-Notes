import matplotlib.pyplot as plt
import numpy as np

plt.rcParams['font.sans-serif'] = ['SimHei']  # 用来正常显示中文标签

x = [1, 2, 3, 4]
y = [0, -5, -6, 3]
# x = [0,1,2]
# y = [1,2,3]

def Lagrange(x, y, X):
    n = len(x)
    sum = 0.0

    for i in range(n):
        f = y[i]
        for j in range(n):
            if i != j:
                f *= (X - x[j]) / (x[i] - x[j])
        sum += f

    return sum

#绘制函数图像
a = Lagrange(x,y,5)
print(a)
yy = []
plt.scatter(5,a,c = 'r',label = '预测点')

xx = np.arange(0,10,0.1)
for i in xx:
    yy.append(Lagrange(x,y,i))

plt.plot(xx,yy,label = '插值曲线')
plt.title('拉格朗日插值法')
plt.legend(loc="upper left")
plt.show()