#### 题目描述

* 输入一个链表，输出该链表中倒数第k个结点。

* 实现思想

  * 设两个结点指针`p1`,`p2`，让`p1`先移动`k`个，然后`p1`,`p2`同时移动，当`p1==null`时，`p2`所指结点就是所求结点。

* 实现代码

  * `c++`

    ```c++
    /*
    struct ListNode {
    	int val;
    	struct ListNode *next;
    	ListNode(int x) :
    			val(x), next(NULL) {
    	}
    };*/
    class Solution {
    public:
        ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
            ListNode *p1,*p2;
            int i = 0;
            p1 = pListHead;
            p2 = pListHead;
            while (k > 0 && p1 != NULL){
                p1 = p1->next;
                k--;
            }
            if(p1 == pListHead || (p1 == NULL && k > 0)){
                return NULL;
            }
            while (p1 != NULL){
                p1 = p1->next;
                p2 = p2->next;
            }
            return p2;
        }
    };
    ```

  * `java`

    ```java
    /*
    public class ListNode {
        int val;
        ListNode next = null;
    
        ListNode(int val) {
            this.val = val;
        }
    }*/
    public class Solution {
        public ListNode FindKthToTail(ListNode head,int k) {
            ListNode p1,p2;
            int i = 0;
            p1 = head;
            p2 = head;
            while (k > 0 && p1 != null){
                p1 = p1.next;
                k--;
            }
            if(p1 == head || (p1 == null && k > 0)){		//p1 指向head说明k<=0,p1==null && k>0说明 k超过了链表的长度
                return null;
            }
            while (p1 != null){
                p1 = p1.next;
                p2 = p2.next;
            }
            return p2;
        }
    }
    ```

    