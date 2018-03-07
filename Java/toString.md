# toString
* 返回该对象的字符串表示。
* toString方法相当于：
```
Demo d1 = new Demo();
Class c = d1.getClass();//获取当前运行的类
 System.out.println(c.getName()+"@"+Integer.toHexString(d1.hashCode()));
System.out.println(d1.toString());
```
```
打印输出
Day6.Demo@1540e19d
Day6.Demo@1540e19d
```
# hasCode
* 返回对象的哈希值
