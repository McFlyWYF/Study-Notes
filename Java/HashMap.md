### HashMap中的key如果是Object，则需要实现哪些方法？
* hashCode方法和equals方法。
* 因为hashCode方法用来计算Entry在数组中的index索引位置，equals方法用来比较数组指定index索引位置上链表的节点Entry元素是否相等。否则由于hashCode方法实现不恰当会导致严重的hash碰撞，从而使HashMap会退化成链表结构而影响性能。

### 比较一下两种遍历方法
* 第一种
```java
Map map = new HashMap();
Iterator iter = map.entrySet().Iterator();
while(iter.hashNext()){
    Map.Entry entry = (Map.Entry) iter.next();
    Object key = entry.getkey();
    Object val = entry.getValue();
}
```
* 第二种
```java
Map map = new HashMap();
Iterator iter = map.keySet().Iterator();
while(iter.hashNext()){
    Object key = iter.next();
    Object val = map.get(key);
}
```
* 第一种方法效率更高且推荐使用。
* 因为HashMap的两种遍历是分别对keySet和entrySet进行迭代，对于keySet实质上是遍历了两次，一次是转为iterator迭代器遍历，一次就从HashMap中取出key所对于的value操作；而entrySet方式值遍历了一次，它把key和value都放到了Entry中，所以效率高。

### 为什么HashMap中的String、Integer这样的包装类适合作为key键，即为什么使用它们可以减少哈希碰撞？
* 因为String、Integer等包装类时final类型的，具有不可变性，而且已经重写了equals()和hashCode()方法。不可变性保障了计算hashCode()后键值的唯一性和缓存特性，不会出现放入和获取时哈希码不同情况且读取哈希值的高效性。

### 分析下面的程序
```java
class Item{
  public String name;
  public int age;

  @Override
  public int hashCoe(){
    return this.name.hashCode() + this.age;
  }

  public Item(String name,int age){
    this.name = name;
    this.age = age;
  }
}

public class Demo{
  public static void main(String[] args){
    Item item1 = new Item("android",4);
    Item item2 = new Item("java",3);
    Map<Item,Item> map = new HashMap<Item,Item>();
    map.put(item1,item1);
    map.put(item2,item2);

    item2.name = "unix c";
    Item value = map.get(item2);
    System.out.println("value=" + value);
  }
}
```
* 输出结果为value = null。
* 因为key更新后hashCode也更新了，而HashMap里面的对象时我们原来哈希值的对象，在get时由于哈希值已经变了，原来的对象不会被索引到了，所以结果为null，因此当把对象放到HashMap后就不要尝试对key进行修改操作，防止出现哈希值变化或者equals比较不等的情况导致无法索引。

### HashMap的底层原理
* 当我们往HashMap中put元素时，先根据key的hash值得到这个Entry元素在数组中的位置，然后把这个Entry元素放到对应的位置上，如果这个Entry元素所在的位置是已经存放有其他元素，就在同一位置上的Entry元素以链表的形式存放，新加入的放在链头,从HashMap中get Entry元素时先计算key的hashcode，找到数组中对应位置的某一Entry元素，然后通过key的equals方法在对应位置的链表中找到需要的Entry元素，所以HashMap的数据结构是数组和链表的结合。此外，HashMap中key和value都允许为null，key为null的键值对永远都放在以table[0]为头结点的链表中。
* 之所以HashMap这么设计的实质是由于数组存储区间是连续的，占用内存严重，故空间复杂度大，但二分法查找时间复杂度小 (O(1))，所以寻址容易而插入困难；而链表存储区间离散，占用内存比较宽松，故空间复杂度小，但时间复杂度大(O(n)),所以寻址困难而插入比较容易；所以就产生了一种新的数据结构叫做哈希表，哈希表既满足数据的查找方便，同时不占用太多的内存空间，使用也比较方便，哈希表有多种不同的实现方法，HashMap采用的是链表的数组实现方式。

### HashMap默认的初始化长度以及默认长度和扩容后的长度为什么都是2的幂
* 在JDK中默认长度是16（在Android SDK中的HashMap默认长度是4），并且默认长度和扩容后的长度都必须是2的幂。
