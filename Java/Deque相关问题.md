### 什么是Deque以及ArrayDequeyuArrayList的区别及特点
* Deque是一个双端队列接口，Deque扩展了Queue，有队列的所有方法，还可以看作栈，有栈的基本方法push/pop/peek,还有明确的操作两端的方法 addFirst/removeLast等。
```java
void addFirst(Object e);//将指定元素插入双向队列开头
void addLast(Object e);//将指定元素插入双向队列末尾
Iterator descendingIterator();//返回对应的迭代器，逆向迭代队列中的元素
Object getFirst();//获取但不删除队列第一个元素
Object getLast();//获取但不删除队列最后一个元素
boolean offerFirst(Object e);//将指定元素插入双向队列开头
boolean offerLast(Object e);/将指定元素插入双向队列末尾
Object peekFirst();//获取但不删除队列第一个元素
Object peekLast();//获取但不删除队列最后一个元素
Object pollFirst();//获取并删除队列第一个元素
Object pollLast();//获取并删除队列最后一个元素
Object pop();//退栈输出队列第一个元素
void push(Object e);//将元素入栈
Object removeFirst();//获取并删除队列第一个元素
Object removeFirstOccurence(Object e);//删除队列第一次出现的元素e
removeLast()//获取并删除队列最后一个元素
Object removeFirstOccurence(Object e);//删除队列最后一次出现的元素e
```

* LinkedList既实现了List接口又实现了Deque接口，而LinkedList的实现是基于双向链表结构的，容量没有限制，是非并发安全的队列，不仅可以当成列表使用，而且可以当做双向队列使用，同时也可以当做栈使用。此外，LinkedList的元素可以为null值。

* ArrayDeque是一个用数组实现的双端队列，为了满足可以在数组两端进行插入和删除，该数组必须是循环的。也就是数组的任何一点可以看做是起点或者是终点。ArrayDeque是非线程安全的，当多个线程同时使用的时候需要手动同步，该容器不允许放null元素，没有索引位置，不能根据索引进行操作。

### ArrayDeque和LinkedList的适用场景
* ArrayDeque和LinkedList都实现了Deque接口，如果只需要Deque接口且从两端进行操作，则一般来说ArrayDeque效率更高一些。如果同时需要根据索引位置进行操作，应该优先选择LinkedList。
