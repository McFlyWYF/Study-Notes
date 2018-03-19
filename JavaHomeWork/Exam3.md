### 输入一个1-99999之间的数，输出它的位数，并判断是否是回文数
```java
package JavaHomeWork;

import java.util.Scanner;

//输入一个1-99999之间的数，输出它的位数，并判断是否是回文数
public class Exam3 {
    public static void main(String[] args){
        int j = 0;
        Scanner input =  new Scanner(System.in);
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
* 结果打印
```
请随机输入一个1-99999之间的一个数
12346
输入数字的位数是: 5
该数字不是回文数
```
```
请随机输入一个1-99999之间的一个数
34643
输入数字的位数是: 5
该数字是回文数
```
