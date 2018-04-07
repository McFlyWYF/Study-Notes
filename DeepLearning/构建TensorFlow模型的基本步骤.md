## 构建TensorFlow模型的基本步骤
### 第一步：安装
#### 加载MNIST数据
* 我们自动下载和导入MNIST数据集，会自动创建一个`MNIST_data`的目录存储数据。
```Python
import input_data
mnist = input_data.read_data_sets('MNIST_data',one_hot=True)
```

#### 运行TersonFlow的InteractiveSession
* 使用InteractiveSession()可以在运行图的时候，插入计算图，如果不使用InteractiveSession,需要在启动Session之前构建整个计算图，然后启动该计算图。
```Python
import tensorflow as tf
sess = tf.InteractiveSession()
```

#### 计算图
### 第二步：构建softmax回归模型
* 这里构建的是一个线性层的softmax回归模型

#### 占位符
* 通过输入图像和目标输出类别来创建节点，开始构建计算图。
```Python
x = tf.placeholder("float",shape = [None,784])
y_ = tf.placeholder("float",shape = [None,10])
```
* 这里的x和y_只是一个占位符，可以在运行某一计算时输入具体的值。x是一个二维张量，784是MNIST图片的维度，None表示大小不定。y_也是一个二维张量，10表示某一MNIST图片的类别。

#### 变量
* 定义模型权重 W 和偏置 b ，作为额外的输入量。将这些模型参数用Variable来表示，代表着计算图中的每一个值在计算过程中可以使用和修改。
```Python
W = tf.Variable(tf.zeros([784,10]))
b = tf.Variable(tf.zeros[10])
```
* 这里将 W 和 b 初始化为零向量。W 是一个784x10的矩阵，一张图片有784个特征和10个输出值。b 是一个10位的向量，因为有10个分类。
* 变量需要通过session初始化后，才能在session中使用。
```Python
sess.run(tf.initialize_all_variables())
```

#### 类别预测与损失函数
* 我们把向量化后的图片 x 和权重矩阵 W 相乘，加上偏置 b ，然后计算每个分类的softmax概率值。
```Python
y = tf.nn.softmax(tf.matmul(x,W) + b)
```

* 可以为训练过程指定最小化误差的损失函数，我们的损失函数是目标类别和预测类别之间的交叉熵。
```Python
cross_entroy = -tf.reduce_sum(y_ * tf.log(y))
```

* 这里的tf.reduce_sum把每张图片的交叉熵值都加起来了。

### 第三步：训练模型
* 我们用速下降算法让交叉熵下降，步长为0.01.
```Python
train_step =tf.train.GradientDescentOptimizer(0.01).minimize(cross_entropy)
```

* 返回的train_step操作对象，在运行时使用梯度下降来更新参数，整个模型的训练通过反复运行train_step来完成。
```Python
for i in range(1000):
  batch = mnist.train.next_batch(50)
  train_step.run(feed_dict = {x:batch[0],y_:batch[1]})
```

* 每一步迭代，都会加载50个训练样本，然后执行一次train_step，通过feed_dict将 x 和 y_ 张量的占位符用训练样本数据代替。

#### 评估模型
* 首先要找出预测正确的标签，tf.argmax 是一个有用的函数，能给出某个tensor对象在某一维上的其数据最大值所在的索引值。标签向量是有0,1组成的，最大值是1。tf.argmax(y,1)返回的是模型对于任一输入预测到的标签值，tf.argmax(y_,1)代表正确的标签。可以使用tf.equal来检测我们的预测是否与真实标签匹配。
```Python
correct_prediction = tf.equal(tf.argmax(y,1),tf.argmax(y_,1))
```

* 这里返回的是一个布尔数组，我们将它转换成浮点数来表示对错，取平均值。
```Python
accuracy = tf.reduce_mean(tf.cast(correct_prediction,"float"))
```

* 最后得出的准确率大概是91%。
