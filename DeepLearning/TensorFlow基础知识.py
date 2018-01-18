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
