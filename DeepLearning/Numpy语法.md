```
import numpy as np   #引入numpy库
import numpy.linalg as lg

#创建一维的narray对象
a1 = np.array([1,2,3,4,5])

#创建二维的narray对象
a2 = np.array([[1,2,3,4,5],[6,7,8,9,10]])

#获取矩阵行列数
print (a2.shape) #结果返回一个元组
print (a2.shape[0])#获得行数
print (a2.shape[1])#获得列数

#矩阵的截取
#按行列截取
print (a2[0:1])#截取第一行
print (a2[1,2:5])#截取第二行，第3,4,5列,不包含头，包含尾
print (a2[1,:])#截取第二行

#按条件截取
b = a2[a2>6]#截取矩阵a2中大于6的元素，范围是一维数组
print (b)
print (a2>6)#返回的是Boolean值

a2[a2>6] = 0#将a2中大于6的元素变为0
print (a2)

#矩阵的合并
a3 = np.array([[1,2],[3,4]])
a4 = np.array([[5,6],[7,8]])
print (np.hstack([a3,a4]))#参数传入的时候以元组或列表的形式传入，hstack是横向合并
print (np.vstack([a3,a4]))#vstack是纵行合并
#还可以使用一下方法进行合并
print (np.concatenate((a3,a4),axis = 0))#纵向
print (np.concatenate((a3,a4),axis = 1))#横向

#通过函数创建矩阵
#arange
a = np.arange(10)#默认从0开始到10，不包括10，步长为1
print (a)

a1 = np.arange(5,10)#从5开始到10，不包括10，步长为1
print (a1)

a2 = np.arange(5,20,2)#从5开始到20，不包括20，步长为2
print (a2)

#linspace,用于创建指定数量等间隔的序列，实际生成一个等差数列。
a = np.linspace(0,10,7)#生成首位是0，末位是10，含7个数的等差数列
print (a)

#logspace,用于生成等比数列。
a = np.logspace(0,2,5)#生成的首位是10的0次方，末位是10的2次方，含5个数
print (a)

#ones 创建全1矩阵,zeros 创建全0矩阵 ,eye 创建单位矩阵 ,empty 创建空矩阵
a_ones = np.ones((3,4))
print (a_ones)

a_zeros = np.zeros((3,3))
print (a_zeros)

a_eye = np.eye(3)
print (a_eye)

a_empty = np.empty((3,3))
print (a_empty)

#fromstring,可以将字符串转化成ndarray对象，需要将字符串数字化时这个方法比较有用，可以获得字符串的ascii码序列。
a = "abcdef"
b = np.fromstring(a,dtype = np.int8)#一个字符是8位
print (b)

#fromfunction,可以根据矩阵的行号列号生成矩阵的元素。
def fun(i,j):
    return i+j

a = np.fromfunction(fun,(5,6))# 第一个参数为指定函数，第二个参数为列表list或元组tuple,说明矩阵的大小
print (a)

#矩阵的运算
# + 加 - 减 * 乘 / 除 % 取余 ** 矩阵每个元素都取n次方，如**2：每个元素都取平方

a = np.array([[1,2,3],[4,5,6]])
b = np.array([[6,5,4],[3,2,1]])
print (a + b)
print (a - b)
print (a * b)
print (a / b)
print (a % b)
print (a**2)

#常用矩阵函数
'''
np.sin(a)	对矩阵a中每个元素取正弦,sin(x)
np.cos(a)	对矩阵a中每个元素取余弦,cos(x)
np.tan(a)	对矩阵a中每个元素取正切,tan(x)
np.arcsin(a)	对矩阵a中每个元素取反正弦,arcsin(x)
np.arccos(a)	对矩阵a中每个元素取反余弦,arccos(x)
np.arctan(a)	对矩阵a中每个元素取反正切,arctan(x)
np.exp(a)	对矩阵a中每个元素取指数函数,e^x
np.sqrt(a)	对矩阵a中每个元素开根号√x
'''

a = np.array([[1,2,3],[4,5,6]])
print (np.sin(a))
#print (np.arcsin(a))
# 当矩阵中的元素不在定义域范围内，会产生RuntimeWarning，结果为nan

#矩阵乘法,dot
a = np.array([[1,2,3],[4,5,6]])
b = np.array([[1,2],[3,4],[5,6]])
print (a.shape[1] == b.shape[0])
print (a.dot(b))

#矩阵的转置,transpose
a = np.array([[1,2,3],[4,5,6]])
print (a.transpose())
#另一种方法
print (a.T)

#矩阵的逆，求矩阵的逆需要先导入numpy.linalg，用linalg的inv函数来求逆。矩阵求逆的条件是矩阵的行数和列数相同。
a = np.array([[1,2,3],[4,5,6],[7,8,9]])
print (lg.inv(a))

a = np.eye(3)
print (lg.inv(a))

#矩阵信息获取
#最大值，最小值
a = np.array([[1,2,3],[4,5,6]])
print (a.max())
print (a.min())
print (a.max(axis = 0))#每列的最大值
print (a.max(axis = 1))#每行的最大值
print (a.argmax(axis = 1))#获得最大值元素所在的位置

#平均值,mean()
a = np.array([[1,2,3],[4,5,6]])
print (a.mean())

print (a.mean(axis = 0))

#方差，var()
a = np.array([[1,2,3],[4,5,6]])
print (a.var())

#标准差,std()
a = np.array([[1,2,3],[4,5,6]])
print (a.std())

#中值指的是将序列按大小顺序排列后，排在中间的那个值，如果有偶数个数，则是排在中间两个数的平均值。median()
a = np.array([[1,2,3],[4,5,6]])
print(np.median(a))
print(np.median(a,axis = 0))

#求和，sum()
a = np.array([[1,2,3],[4,5,6]])
print (a.sum())

#累积和，指的是该位置之前(包括该位置)所有元素的和。cumsum()
a = np.array([[1,2,3],[4,5,6]])
print (a.cumsum())
```
