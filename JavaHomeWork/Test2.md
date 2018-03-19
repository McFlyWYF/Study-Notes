### 用charAt()方法将一个字符串反转后输出
```java
package JavaHomeWork;

import java.util.Scanner;

//用charAt()方法将一个字符串反转后输出
public class Test4 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String s = input.nextLine();

        for (int i = s.length()-1; i >= 0; i--) {
            System.out.print(s.charAt(i) + " ");
        }
    }
}
```
### 查找一个字符串在某个子串中出现的次数
```java
package JavaHomeWork;

import java.util.Scanner;

//查找一个字符串在某个子串中出现的次数
public class Test5 {

    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        System.out.println("输入一个字符串：");
        String s = input.nextLine();
        System.out.println("输入一个要查询的子串：");
        String s1 = input.nextLine();
        int n = 0;//出现下标
        int j = 0;//统计个数

        if (!s.contains(s1)){
            System.out.println("该字符串中不包含该子串");
        }else {
            while (s.indexOf(s1,n) >= 0 && n < s.length()) {

                    j++;
                    n = s.indexOf(s1,n) + s1.length();
            }
        }
        System.out.println("该子串在字符串中出现的次数是：" + j);
    }
}
```
