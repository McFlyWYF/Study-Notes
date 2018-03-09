# Object类
* java中所有对象的直接或间接父类。
* 该类中定义的是所有对象都具备的功能。
* Object类中已经提供了对对象是否相同的比较方法。如果自定义的类中也有比较相同的功能，没有必要重新定义，只要沿袭父类中的功能，建立自己特有的比较内容即可，这就是覆盖。
* equals()方法：
 * equals()方法比较的是对象的内容。
 * == 比较的是对象的地址值。
* 重写父类的equals()方法：
```java
@Override
    public boolean equals(Object obj){
        Demo d = (Demo)obj;//向下转型
        return this.num == d.num;
    }
```
