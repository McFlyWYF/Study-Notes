# String
* `String s1 = "abc"`;//s1是一个类类型变量，“abc”就是一个对象，字符串一旦被初始化就不可以被改变。
* String s1 = "abc";s1 = "bcd";//s1里面的内容没有变，而是s1指向的对象地址改变了。
* `String s1 = new String("abc")`等同于`String s1 = "abc"`
```java
        String s1 = "abc";
        String s2 = "abc";
        String s3 = new String("abc");
         String s4 = new String("abc");

        System.out.println(s1 == s2);//true
        System.out.println(s1.equals(s2));//true

        System.out.println(s1 == s3);//false
        System.out.println(s1.equals(s3));//true,String类复写了Object类中equals方法，用于判断字符串是否相同。

        System.out.println(s3.equals(s4));//true
        System.out.println(s3 == s4);//false
```

### s2 与 s2 的区别
* s1在内存中有一个对象，s2在内存中有两个对象

### String中常见的方法
```java
        System.out.println(s1.length());//获取字符串的长度
        System.out.println(s1.charAt(2));//获取某个位置的字符
        System.out.println(s1.indexOf('a'));//获取某个字符在字符串中第一次出现的位置，该方法还可以判断是否包含子串
        System.out.println(s1.indexOf('a',1));//从指定位置开始获取某个字符在字符串中出现的位置
        System.out.println(s1.lastIndexOf("a"));//反向索引查找字符最后一次出现的位置
        System.out.println(s1.codePointAt(4));//返回指定索引处字符的ASCII值
        System.out.println(s1.equals(s3));//判断内容是否相同
        System.out.println(s1.equalsIgnoreCase(s3));//判断内容是否相同，并且忽略大小写
        System.out.println(s1.isEmpty());//判断字符串是否为空
        System.out.println(s1.endsWith("ac"));//判断字符串是否以某一字符串结尾，返回的是Boolean型，参数是String
        System.out.println(s1.startsWith("ab"));//判断字符串是否以某一字符串开始
        System.out.println(s1.contains("bce"));//判断字符串是否包含某一子串
```
```java
        //字符数组转化为字符串
        char[] arr = {'a','b','c','d'};
        String s = new String(arr);
        System.out.println(s);

        //将字符串转化为字符数组
        String ss = "abcde";
        System.out.println(ss.toCharArray());
```
```java
        System.out.println(s1.replace("a","Hello"));//字符替换,如果要替换的字符不存在，返回的呼死你原串

        String s5 = "zhang,wang,li";
        String[] arr2 = s5.split(",");//切割字符串，‘，’作为分隔符
        for(int i = 0;i < arr2.length;i++){
            System.out.println(arr2[i]);
        }

        System.out.println(s5.substring(6,10));//获取子串，包含头，不包含尾

        String s6 = "    Hello World";
        System.out.println(s6.toUpperCase());//转换为大写
        System.out.println(s6.toLowerCase());//转换为小写
        System.out.println(s6.trim());//去除两端空格
        System.out.println(s1.compareTo(s6));//字符串顺序比较,字符串大于字符串参数返回大于0的数
```
### StringBuffer
#### 是字符串缓冲区，是一个容器，长度是可变化的。可以操作多个数据类型。最终会通过toString方法转化为字符串。
* 存储
 * append()将指定数据作为参数添加到已有数据结尾处。
 ```java
        StringBuffer s = new StringBuffer();
        s.append("abc").append(20);//方法调用链
        System.out.println(s.toString());

        s.insert(1,"Hello");//在指定位置插入数据
        System.out.println(s.toString());
```

* 获取
```java
        StringBuffer s2 = new StringBuffer("abcde");//字符串反转
        s2.reverse();
        System.out.println(s2);

        char[] ch = new char[4];
        s2.getChars(1,4,ch,0);//将缓冲区的指定数据赋值给字符数组
        for (int i = 0;i < ch.length;i++){
            System.out.println(i +" "+ch[i]);
        }
```
* 删除
 * delete()删除指定位置的元素
 ```java
        s.delete(1,3);//删除指定位置的元素
        System.out.println(s.toString());
```
* 修改
```java
        s.setCharAt(2,'E');//修改指定位置的元素
        System.out.println(s);
```

#### StringBuffer是线程同步的，StringBuilder是线程不同步的。多线程建议使用StringBuffer,单线程建议使用StringBulider。开发中，建议使用StringBuilder。
