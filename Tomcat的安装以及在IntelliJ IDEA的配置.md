# Tomcat的安装以及在IntelliJ IDEA的配置

自己想学习java web开发，所以自己进行了环境的搭建，不足的地方欢迎大家多多指出。

### 1. 安装

* 下载地址

  [Tomcat官网](http://tomcat.apache.org/)

  ![1532598765203](C:\Users\16500\AppData\Local\Temp\1532598765203.png)

以上版本任选一个，比如我选的是Tomcat9.0，进入

![1532598858000](C:\Users\16500\AppData\Local\Temp\1532598858000.png)

然后开始下载，下载的是.jar包，需要进行解压，解压的文件夹的名称不能含有中文。

* 启动Tomcat
  * 进入解压Tomcat的文件夹，进入bin目录

![1532599008510](C:\Users\16500\AppData\Local\Temp\1532599008510.png)

这两个都是可以启动Tomcat的，点击启动。

* 停止Tomcat
  * 点击，二者选其一

![1532599057258](C:\Users\16500\AppData\Local\Temp\1532599057258.png)

Tomcat的安装和启动已经介绍完了，下面来教大家怎么在IDEA里面进行Tomcat的配置。

### 2. 配置

Tomcat的配置其实不难，就是一些简单的导入。

* 首先启动IDEA，创建一个新的项目。

  ![1532599287125](C:\Users\16500\AppData\Local\Temp\1532599287125.png)

  点击创建之后，进入下面这个界面，我们选择创建一个Web Application。

![1532599308263](C:\Users\16500\AppData\Local\Temp\1532599308263.png)

选择文件名称和路径。

![1532599378964](C:\Users\16500\AppData\Local\Temp\1532599378964.png)

* 配置环境。

  进入之后，点击如图所示菜单。

  ![1532599584437](C:\Users\16500\AppData\Local\Temp\1532599584437.png)

  进入之后，点击绿色+号，找到![1532599684730](C:\Users\16500\AppData\Local\Temp\1532599684730.png)

  如果没有，点击

  ![1532599706400](C:\Users\16500\AppData\Local\Temp\1532599706400.png)

，找到之后，选择![1532599745757](C:\Users\16500\AppData\Local\Temp\1532599745757.png)

* 下面配置环境

  这里选择解压Tomcat的文件路径。

![1532599797987](C:\Users\16500\AppData\Local\Temp\1532599797987.png)

浏览器选择自己常用的浏览器，个人建议使用火狐或者谷歌。

![1532599871442](C:\Users\16500\AppData\Local\Temp\1532599871442.png)

接下来是Development，点击绿色铅笔。

![1532599958511](C:\Users\16500\AppData\Local\Temp\1532599958511.png)

点击创建一个新的文件夹，新建文件夹-->绿色小加号-->Directory Content选择Web存放的位置 ，当然是Tomcat的webapps了,生成的war文件部署在该项目中才可以在Tomcat服务器上运行。直接运行在web文件夹下的index.jsp文件，做最后验证。 

![1532600078353](C:\Users\16500\AppData\Local\Temp\1532600078353.png)

如果配置成功，会出现如下界面。

![1532600232782](C:\Users\16500\AppData\Local\Temp\1532600232782.png)

* 网页的内容显示在index.jsp文件里。

  ![1532600608616](C:\Users\16500\AppData\Local\Temp\1532600608616.png)

* 以上就是我安装和配置Tomcat的步骤，接下来还会做出补充的，希望对大家有用，看完之后，记得点赞。