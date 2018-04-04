## MNIST数字识别算法思想
### MNIST数据集
* [源码](https://tensorflow.googlesource.com/tensorflow/+/master/tensorflow/g3doc/tutorials/mnist/)
* [数据集](https://tensorflow.googlesource.com/tensorflow/+/master/tensorflow/g3doc/tutorials/mnist/input_data.py)
* [测试数据](http://yann.lecun.com/exdb/mnist/)
* 每个图片数据将被解压为二维的tensor`[image index,pixel index]`，每一项表示某一图片中特定像素的强度值，范围从`[0,255]`到`[-0.5,0.5]`。 "image index"代表数据集中图片的编号, 从0到数据集的上限值。"pixel index"代表该图片中像素点得个数, 从0到图片的像素上限值。

* 每一张图片包含28像素X28像素,我们可以用一个数字数组来表示这张图片:
![Image Text](https://raw.github.com/wangyufei1006/Java-Design-patterns/master/Image/20.png)

我们把这个数组展开成一个向量，长度是 28x28 = 784,从这个角度来看，MNIST数据集的图片就是在784维向量空间里面的点, 并且拥有比较复杂的结构。
![Image Text](https://raw.github.com/wangyufei1006/Java-Design-patterns/master/Image/22.png)
数字n将表示成一个只有在第n维度（从0开始）数字为1的10维向量。比如，标签0将表示成([1,0,0,0,0,0,0,0,0,0,0])。因此， mnist.train.labels 是一个 [60000, 10] 的数字矩阵。

### Softmax回归分析
* Softmax模型可以给不同的对象分配概率。

#### softmax回归分两步：
* 第一步：对图片像素值进行加权求和。如果这个像素足以证明这张图片不属于该类，相应的权值为负，相反则为正。例如:下面这张图片可以对像素值的权值进行解释，红色代表负数权值，蓝色代表正数权值。

![Image Text](https://raw.github.com/wangyufei1006/Java-Design-patterns/master/Image/23.png)
 * 同时需要加入一个偏置量bias，因为输入带有一定的无关干扰量，对于对于给定的输入图片的X代表的数字i的证据可以表示为

 ![Image Text](https://raw.github.com/wangyufei1006/Java-Design-patterns/master/Image/24.png)

 * 其中 `Wi` 代表权重，bi代表数字i类的偏置量，j代表给定图片X的像素索引用于像素求和。用softmax函数可以把这些转换成概率y：

 ![Image Text](https://raw.github.com/wangyufei1006/Java-Design-patterns/master/Image/25.png)

 * 这里的softmax可以看成是一个激励（activation）函数或者链接（link）函数，把我们定义的线性函数的输出转换成我们想要的格式，也就是关于10个数字类的概率分布。因此，给定一张图片，它对于每一个数字的吻合度可以被softmax函数转换成为一个概率值。oftmax函数可以定义为：把输入值当成幂指数求值，再正则化这些结果值。

  ![Image Text](https://raw.github.com/wangyufei1006/Java-Design-patterns/master/Image/26.png)

 * 展开等式右边的子式，可以得到：

 ![Image Text](https://raw.github.com/wangyufei1006/Java-Design-patterns/master/Image/27.png)

  * softmax函数回归模型，对于输入的X加权求和，再分别加上一个偏置量，最后输入到softmax函数中：

![Image Text](https://raw.github.com/wangyufei1006/Java-Design-patterns/master/Image/28.png)

  * 把它写成一个等式，可以得到：

 ![Image Text](https://raw.github.com/wangyufei1006/Java-Design-patterns/master/Image/29.png)

  * 我们也可以用向量表示这个计算过程：用矩阵乘法和向量相加。

 ![Image Text](https://raw.github.com/wangyufei1006/Java-Design-patterns/master/Image/30.png)
  * 进一步，我们可以写成如下方式：

   ![Image Text](https://raw.github.com/wangyufei1006/Java-Design-patterns/master/Image/31.png)
