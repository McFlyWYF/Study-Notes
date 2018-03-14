
## String
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

#### s2 与 s2 的区别
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

