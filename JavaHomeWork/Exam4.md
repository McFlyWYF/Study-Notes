## 编三个继承类，三个类要有构造方法
* Employee.java
```java
package JavaHomeWork.Exam4;

public class Employee {

    private String name;

    public Employee(String name){
        this.name = name;
    }

    public void print(){
        System.out.println(name);
    }

}
```
* Worker.java
```java
package JavaHomeWork.Exam4;

public class Worker extends Employee{

    private String no;

    public Worker(String name,String no) {
        super(name);
        this.no = no;
    }

    public void print(){
        super.print();
        System.out.println(no);
    }
}
```
* HourlyWorker.java
```java
package JavaHomeWork.Exam4;

public class HourlyWorker extends Worker {

    private int money;

    public HourlyWorker(String name,String no,int money){
        super(name,no);
        this.money = money;
    }

    public void print(){
        super.print();
        System.out.println(money);
    }
}
```
* Demo.java测试类
```java
package JavaHomeWork.Exam4;

public class Demo {

    public static void main(String[] args) {
        Employee e = new Employee("小王");
        e.print();

        Worker w = new Worker("小张","16070941");
        w.print();

        HourlyWorker h = new HourlyWorker("小李","16070942",2600);
        h.print();
    }
}
```
