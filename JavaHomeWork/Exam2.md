### 猜数游戏
```java
package JavaHomeWork;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

//猜数游戏
public class Exam2 {

    public static void main(String[] args){

        boolean judge = true;
        Scanner input = new Scanner(System.in);
        Random r = new Random();
        int num = r.nextInt(100);//随机生成100以内的随机数
        while (judge){
            System.out.println("请输入一个数：");
            int n = input.nextInt();
            if (n < num){
                System.out.println("输入的数太小，请重新输入:");
                judge = true;
            }else if (n > num){
                System.out.println("输入的数太大，请重新输入:");
                judge = true;
            }else if (n == num){
                System.out.println("恭喜你，猜数成功!!!");
                judge = false;
            }
        }
        System.out.println("随机生成的数字是："+num);
    }
}
```
### 逆序输出一维数组
```java
public class Exam2 {
    public static void main(String[] args){
        int[] a = {10,42,7,31,25,68,90,100,0,55};
        int[] b = new int[a.length];
        for(int i = a.length - 1,j= 0;i >= 0;i--,j++){
            b[j] = a[i];
        }
        for (int i = 0;i < b.length;i++) {
            System.out.print(b[i]+" ");
        }
    }
}
```
### 输出希腊字母表
```java
public class Exam2 {
    public static void main(String[] args) {
        char a = 'A';
        for(int i = 0;i < 26;i++){
            System.out.print((char)(a + i) + " ");
        }
    }
}
```

### 输出数组名和数组的元素
```java
public class Exam2 {
    public static void main(String[] args) {
        int[] a = {10,42,7,31,25,68,90,100,0,55};
        for (int i = 0;i < a.length;i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println(a);
    }
}
```
