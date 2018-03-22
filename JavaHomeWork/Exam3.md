## 输入一个1-99999之间的数，输出它的位数，并判断是否是回文数

```java
package JavaHomeWork;
import java.util.Scanner;
public class Exam3 {
    public static void main(String[] args){
        int j = 0;
        Scanner input =  new Scanner(System.in);
        System.out.println("请随机输入一个1-99999之间的一个数");
        int n = input.nextInt();
        if (n >= 0 && n <= 99999){
            String s = String.valueOf(n);//将输入的整数转换为字符串
            System.out.println("输入数字的位数是: "+s.length());

            char[] a = new char[s.length()];//定义字符数组
            for(int i = s.length() - 1;i >= 0;i--){
                a[j++] = s.charAt(i);//将字符串s中每个元素赋值到字符数组a中
            }
            String s1 = String.valueOf(a);//将字符数组转换为字符串
            if (s1.equals(s)){
                System.out.println("该数字是回文数");
            }else {
                System.out.println("该数字不是回文数");
            }
        }else {
            System.out.println("输入的数字不在指定范围内，请重新输入");
        }
    }
}
```

## 输出200以内的所有奇数

```java
public class Exam3 {
    public static void main(String[] args) {
        int j = 0;
        for(int i = 0;i < 200;i++) {
            if (i % 2 != 0) {
                System.out.print(i + " ");
                j++;
            } else if (j % 10 == 0){
                System.out.println();
            }
        }
    }
}
```

## 输出下三角的九九乘法表

```java
public class Exam3 {
    public static void main(String[] args) {
        for(int i = 1;i <= 9;i++){
            for(int j = 1;j <= i;j++){
                System.out.print(j+"*"+i+"="+j*i+" ");
            }
            System.out.println();
        }
    }
}
```
## 
```java
public class Exam3 {
    public static void main(String[] args) {
        int[][] a = {{0}, {1, 2}, {2, 3, 4}, {3, 4, 5, 6}};
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j <= i; j++) {
                System.out.print(a[i][j] + " ");
            }
            System.out.println();
        }
    }
}
```

## 求最大值，最小值，平均值，和
```java
public class Exam3 {
    public static void main(String[] args) {
        int[] a = new int[10];
        for (int i = 0; i < 10; i++) {
            Scanner input = new Scanner(System.in);
            a[i] = input.nextInt();
        }

        int max = a[0];
        int min = a[0];
        int sum = 0;
        int average = 0;

        for (int i = 0; i < a.length; i++) {
            if (a[i] > max) {                      //求最大值
                max = a[i];
            }
            if (a[i] < min) {                     //求最小值
                min = a[i];
            }
            sum = sum + a[i];                    //求和
        }
        average = sum / 10;
        System.out.println("最大值是: " + max + " 最小值是: " + min + " 平均值是: " + average + " 所有元素和为: " + sum);
    }
}
```

## 打印字母正三角形

```java
public class Exam3 {
    public static void main(String[] args) {

        for (int i = 1,x = 0; i <= 7; i++,x++) {
            for (int j = 7 - i; j >= 0; j--) {
                System.out.print("  ");
            }
            for (int k = 1; k <= 2 * i - 1; k++) {
                System.out.print((char) ('A' + x) + " ");
            }
            System.out.println();
        }
    }
}
```
