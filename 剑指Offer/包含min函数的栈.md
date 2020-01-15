#### 题目描述

* 定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。

* 实现思想

  * 创建两个栈，一个data栈，一个min栈。

    * data栈 依次入栈元素 5,   4,   3,   8,   10,   11,   12,   1；
    * min栈 依次入栈元素 5， 4,   3，3,    3，  3，   3， 1。

    出栈时，min的栈与栈data均要出栈。

* 实现代码

  * `java`

    ```java
    import java.util.Stack;
    
    public class Solution {
    Stack data = new Stack();   //数据栈
        Stack min = new Stack();    //最小数栈
    
        public void push(int node) {
            data.push(node);
            if (min.isEmpty() || (int) min.peek() > node) {     //入栈元素小于最小数栈
                min.push(node);
            } else {
                min.push(min.peek());
            }
        }
    
        public void pop() {
            data.pop();
            min.pop();
        }
    
        public int top() {
            return (int) data.peek();
        }
        
        public int min() {
            return (int) min.peek();
        }
    }
    ```

    