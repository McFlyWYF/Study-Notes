# Tensorflow示例代码演示
* Python 程序生成了一些三维数据, 然后用一个平面拟合它.
```python
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

#最小化方差

loss = tf.reduce_mean(tf.square(y - y_data))
optimizer = tf.train.GradientDescentOptimizer(0.5)
train = optimizer.minimize(loss)

#初始化变量

init = tf.initialize_all_variables()

#启动图

sess = tf.Session()
sess.run(init)

#拟合平面

for step in xrange(0,201):
    sess.run(train)
    if step % 20 == 0:
        print (step,sess.run(w),sess.run(b))

# 最佳拟合结果 w: [[0.100  0.200]]  b: [0.300]
```
* 结果打印
```
0 [[ 0.69495839 -0.17597622]] [ 0.36398971]
20 [[ 0.22417282  0.09297399]] [ 0.28628224]
40 [[ 0.1293367   0.17396133]] [ 0.29714942]
60 [[ 0.10690498  0.19362873]] [ 0.29945487]
80 [[ 0.10161681  0.19842969]] [ 0.29991305]
100 [[ 0.10037585  0.19960944]] [ 0.29999304]
120 [[ 0.10008649  0.19990177]] [ 0.30000272]
140 [[ 0.10001962  0.19997498]] [ 0.30000207]
160 [[ 0.10000434  0.19999351]] [ 0.30000094]
180 [[ 0.10000092  0.19999827]] [ 0.3000004]
200 [[ 0.1000002   0.19999954]] [ 0.30000013]
```
`最佳拟合结果 w: [[0.100  0.200]]  b: [0.300]`
