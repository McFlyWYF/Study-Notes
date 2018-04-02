## 单例模式的实现
#### 实现单例模式，就是在实例化的时候，只实例化一次，java中类加载只加载一次，所以把实例化过程设置为static
* 饿汉式
```java
package JavaHomeWork.singleton;

public class Singleton {
    /*
    饿汉式
     */
    private static Singleton s = new Singleton();

    private Singleton(){}

    public static Singleton getInstance(){
        return s;
    }

    public void print(){
        System.out.println("我是饿汉式单例模式");
    }

}
```
* 懒汉式
```java
package JavaHomeWork.singleton;

public class Singleton1 {

     /*
    懒汉式
     */

    private static Singleton1 s1 = null;
    private Singleton1(){}

    public static Singleton1 getInstance(){
        if (s1 == null){
            s1 = new Singleton1();
        }
        return s1;
    }

    public void print(){
        System.out.println("我是懒汉式单例模式");
    }
}
```
* 测试类
```java
package JavaHomeWork.singleton;

public class Demo {

    public static void main(String[] args) {
        Singleton s1 = Singleton.getInstance();
        Singleton s3 = Singleton.getInstance();
        s1.print();
        System.out.println(s1 == s3);//true

        Singleton1 s2 = Singleton1.getInstance();
        s2.print();

    }
}
```
