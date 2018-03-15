* 输入一个数，输入该数所在的季节
```java
package JavaHomeWork;

import java.util.Scanner;

public class Test1 {

    public static void main(String[] args){

        Scanner input = new Scanner(System.in);
        int month = input.nextInt();

        switch (month){
            case 12:
            case 1:
            case 2:
                System.out.println("Winter");
                break;
            case 3:
            case 4:
            case 5:
                System.out.println("Spring");
                break;
            case 6:
            case 7:
            case 8:
                System.out.println("Summer");
                break;
            case 9:
            case 10:
            case 11:
                System.out.println("Autumn");
                break;
        }
    }
}
```
* 输入两个数比较大小，按从小到大输出

```java
  package JavaHomeWork;

import java.util.Scanner;

public class Test2 {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        int a = input.nextInt();
        int b = input.nextInt();

        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }

        System.out.println(a+" "+b);
    }
}
```
* 输出10-50之间能被3整除的数

```java
package JavaHomeWork;

public class Test3 {

    public static void main(String[] args){
        for(int i = 10;i <= 50;i++){
            if (i % 3 == 0){
                System.out.println(i);
            }
        }
    }
}
```
