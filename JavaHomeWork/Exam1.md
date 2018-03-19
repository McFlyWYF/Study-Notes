### 输出自己的学号姓名
```java
package JavaHomeWork;

import java.util.Scanner;

public class Exam1 {
    public static void main(String[] args){

        Scanner input = new Scanner(System.in);
        System.out.println("请输入姓名");
        String name = input.nextLine();//输入姓名
        System.out.println("请输入学号");
        String id = input.nextLine();//输入学号
        System.out.println("姓名："+name+" 学号："+id);
    }
}
```
