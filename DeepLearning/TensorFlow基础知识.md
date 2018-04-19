```Python
import tensorflow as tf
import numpy as np

# 使用Numpy生成假数据，总共100个点
from numpy.core.tests.test_mem_overlap import xrange

x_data = np.float32(np.random.rand(2, 100))
y_data = np.dot([0.100, 0.200], x_data) + 0.300

# 构造一个线性模型

b = tf.Variable(tf.zeros([1]))
w = tf.Variable(tf.random_uniform([1, 2], -1.0, 1.0))
y = tf.matmul(w, x_data) + b

# 最小化方差

loss = tf.reduce_mean(tf.square(y - y_data))
optimizer = tf.train.GradientDescentOptimizer(0.5)
train = optimizer.minimize(loss)

# 初始化变量

init = tf.initialize_all_variables()

# 启动图

sess = tf.Session()
sess.run(init)

# 拟合平面

for step in xrange(0, 201):
    sess.run(train)
    if step % 20 == 0:
        print(step, sess.run(w), sess.run(b))

# 最佳拟合结果 w: [[0.100  0.200]]  b: [0.300]

hello = tf.constant("Hello Tensorflow")
sess = tf.Session()
print(sess.run(hello))

a = tf.constant(10)
b = tf.constant(20)
print(sess.run(a + b))

# 创建一个常量op，产生一个1x2矩阵，这个op被作为一个节点
# 加到默认图中
# 构造器的返回值代表该常量 op 的返回值
matrix1 = tf.constant([[3., 3.]])

# 创建另一个常量op，产生一个2x1矩阵
matrix2 = tf.constant([[2.], [2.]])

# 创建一个矩阵乘法matmul op,把matriax1 和 matriax2 作为输入，product作为结果输出
product = tf.matmul(matrix1, matrix2)

result = sess.run(product)
print(result)

# 显示关闭会话
sess.close()

# 使用 with 代码块自动完成关闭动作
with tf.Session() as sess:
    result = sess.run([product])
    print(result)

# with...Device 指派特定的 GPU 或 CPU 执行操作
with tf.Session() as sess:
    with tf.device("/cpu:0"):
        matrix3 = tf.constant([[2., 2.]])
        matrix4 = tf.constant([[3.], [3.]])
        product1 = tf.matmul(matrix3, matrix4)
        print(sess.run(product1))

print()
# 文档中的 Python 示例使用一个会话 Session 来 启动图, 并调用 Session.run() 方法执行操作.
# 为了便于使用诸如 IPython 之类的 Python 交互环境, 可以使用 InteractiveSession 代替 Session 类, 使用
# Tensor.eval() 和 Operation.run() 方法代替 Session.run() . 这样可以避免使用一个变量来持有会话.

# 进入一个交互式会话
sess = tf.InteractiveSession()

x = tf.Variable([1.0, 2.0])
a = tf.constant([3.0, 3.0])

# 使用初始化器 initializer op 的run()方法初始化x
x.initializer.run()

# 增加一个减法 sub op,从 x 减 a，运行减法op，输出结果
sub_a = tf.subtract(x, a)
print(sub_a.eval())

print()
# Tensor 数据，计算图中，操作间传递的数据都是 tensor，一个tensor包括一个静态类型rank和一个shape

# 创建一个变量，初始化为标量 0
state = tf.Variable(0, name="counter")

# 创建一个op，其作用是使 state 加 1
one = tf.constant(1)
new_values = tf.add(state, one)
update = tf.assign(state, new_values)

# 启动图后，变量必须先经过初始化
init_op = tf.global_variables_initializer()

# 启动图，运行op
with tf.Session() as sess:
    sess.run(init_op)                     # 运行 init
    print(sess.run(state))                # 打印原始state

    for a in range(5):
        sess.run(update)                  # 更新 state,并打印 state
        print(sess.run(state))
```
## 使用神经网络解决分类问题的基本步骤
* 提取问题中实体的特征向量作为神经网络的输入
* 定义神经网络的结构，并定义如何从神经网络输入得到输出
* 通过训练数据来调整神经网络参数的值
* 使用训练好的神经网络来预测未知的数据

## 前向传播算法
* 神经网络的前向传播算法需要三部分信息：
 * 第一部分是神经网络的输入
 * 第二部分是神经网络的连接结构
 * 第三部分是每个神经元的参数

* 例如：如图所示

![Image Text](https://raw.github.com/wangyufei1006/Java-Design-patterns/master/Image/35.png)

* 首先，这个神经网络有三层，输入层，隐藏层，输出层。输入层有x1,x2，隐藏层是a11,a12,a13。输出层是y。
* 首先，我们可以计算出隐藏层三个节点的值，a11 = w11*x1 + w21*x2,a12 = w12*x1 + w22*x2,a13 =  w13*x1 + w23*x2。然后再次通过类似方法，计算出y的值。y = a11 * w11 + a12 * w21 + a13 * w31,得到y的值，也就是输出值。
* 当然，向前传播算法可以用矩阵来实现。将输入 x1,x2看做是1x2的矩阵，w看做是2x3的矩阵。将隐藏层的三个节点可以看做是向量x和w乘积的取值。
* 使用代码实现是很容易理解的
```Python
a = tf.matmul(x,w1)
y = tf.matmul(a,w2)
```
* 权重声明
```Python
weight = tf.Variable(tf.random_normal([2,3],stddev=2))#stddev是指标准差为2
```

```
#随机数生成函数

tf.random_normal  正态分布
tf.truncated_normal  正态分布,偏离平均值超过2个，重新随机分配
tf.random_uniform  平均分布
tf.random_gamma  Gamma分布


#常数生成函数

tf.zeros  全0数组
tf.ones   全1数组
tf.fill([2,3],9)   全部为给定数字9的数组
tf.constant([1,2,3])   给定值1,2,3的常量
```
* 偏置项通常会使用常数来设置初始值
```Python
biases = tf.Variable(tf.zeros([3]))
```
* 前向传播算法的代码实现

```Python
#前向传播算法
import tensorflow as tf
#声明两个变量
w1 = tf.Variable(tf.random_normal([2,3],stddev=1,seed=1))
w2 = tf.Variable(tf.random_normal([3,1],stddev=1,seed=1))

#暂时将输入特征向量定义为一个常量，x是一个1x2的矩阵
x = tf.constant([[0.7,0.9]])

a = tf.matmul(x,w1)
y = tf.matmul(a,w2)


sess = tf.Session()

#sess.run(w1.initializer)#初始化w1
#sess.run(w2.initializer)#初始化w2

#初始化的改进方法
init_op  = tf.global_variables_initializer()
sess.run(init_op)
print(sess.run(y))
print(tf.all_variables())
sess.close()
```

* 凡是定义过的变量，在使用之前，必须要进行初始化操作`init_op  = tf.global_variables_initia
lizer()`
#### Tensorflow的重要属性
* 张量tensor  维度shape   类型type
* 变量的类型是不可改变的，一旦构建之后，类型就不能再改变了
* 维度在运行时是有可能改变的，但是需要通过设置参数validate_shape = False。

### 常用的非线性激活函数
* ReLU函数：
 * f(x) = max(x,0)
![Image Text](https://raw.github.com/wangyufei1006/Java-Design-patterns/master/Image/37.png)

* sigmoid函数
 * f(x) = 1/1+e(-x)
 ![Image Text](https://raw.github.com/wangyufei1006/Java-Design-patterns/master/Image/38.png)

* Tanh函数
 * f(x) = [1-e(-2x)]/[1+e(-2x)]
 ![Image Text](https://raw.github.com/wangyufei1006/Java-Design-patterns/master/Image/39.png)

### 分类问题
* 一共有7种不同的非线性激活函数，常见的有 `tf.nn.relu`,`tf.sigmoid`,`tf.tanh`
* 常用的损失函数是交叉熵 `y = - 求和(-p * log(q))`，它刻画的是预测值概率和正确值概率之间的距离。p代表的是正确答案，q代表的是预测值。
* softmax 函数是将输出结果变为概率分布，用概率的形式来表示输出值。

### 回归问题
* 回归问题，解决的是对具体数值的预测，输出的是一个任意实数。对于回归问题，最常用的损失函数是均方误差。
```
mes = (求和(y_ - y)^2)/n
```
* 代码形式实现均方误差损失函数
```Python
mes = tf.reduce_mean(tf.square(y_ - y))//这里的减号也是对应元素相减
```

### 自定义损失函数
* 比如：预测商品销量时，少预测一个少挣10元，多预测一个少挣1元，将利润与损失函数相联系。
* 使用代码实现这个损失函数
```Python
loss = tf.reduce_sum(tf.select(tf.greater(v1,v2),(v1 - v2) * a,(v2 - v1) * b))
```
* tf.greater的输入是两个张量，此函数会比较这两个张量中每一个元素的大小，并返回比较结果。当tf.greater的输入张量维度不一样时，会进行类似numpy的广播操作处理。tf.select有三个参数，第一个为选择条件依据，当选择条件为true时，tf.select函数会选择第二个参数中的值，否则使用第三个参数的值。
* tf.select 和 tf.greater 函数的用法
```Python
import
