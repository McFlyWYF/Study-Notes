# MySQL的下载，安装和配置
### 第一步下载
* [下载地址](https://dev.mysql.com/downloads/mysql/)选择和自己电脑匹配的位数

### 第二步安装
* 将下载的MySQL安装包解压到自己想保存的文件夹即可。

### 环境配置
* 在环境变量path里添加MySQL解压后的bin目录的地址，比如我的是：D:\MySQL\mysql-5.7.21-winx64\bin
* 以管理员身份运行cmd，进入MySQL的bin目录下。
* 安装MySQL，cmd中输入`mysqld -install`。
* 接着输入`mysqld --initialize`。

### 配置MySQL的启动文件
* 如果解压后的MySQL中有一个名为my-default.ini的文件，则在配置文件中输入以下几项：
```
basedir=D:\mysql-5.7.20-winx64          //mysql安装地址
datadir=D:\mysql-5.7.20-winx64\data     //文件夹data的地址
port=3306
```
如果没有自己创建一个，添加
```
[mysqld]
basedir=D:\mysql-5.7.20-winx64
datadir=D:\mysql-5.7.20-winx64\data
port=3306
```
* 启动MySQL服务：进入MySQL的bin目录(经过前面的步骤，此时正处于MySQL的bin目录下)，输入`net start mysql`.
* 登陆MySQL，接着输入下面这条命令：`mysql -u root -p`。 这里要求我们输入密码，这个密码就是MySQL自动生成的初始密码，打开data文件夹，找到.err文件，里面有密码。
* 修改初始密码`set password for root@localhost=password('自己设置的密码');`
* 退出MySQL：接着输入`quit`。
* 使用新密码登陆(必须处于MySQL的bin目录下)，输入`mysql -u root -p`。
