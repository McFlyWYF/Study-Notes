### C++ STL

#### vector

* 添加头文件`#include<vector>`和`using namespace std;`

* 定义`vector<typeame>name;`变长数组

  ```c++
  vector<int> name;
  vector<double> name;
  相当于 name[SIZE];
  如果typename是vector，则vector<vector<int>> name;
  ```

* 二维数组 `vector<typename> Arrayname[arraySize];`

  例如：`vector<int>  v[100];`

* vector容器内元素的访问（通过下标或迭代器访问）

  * 通过下标访问

    * `vector<int> name;`    `name[0]`

  * 通过迭代器访问（类似指针）

    * 定义`vector<int>::iterator it;`

    * 通过`*it`访问vector里的元素。

    * ```c++
      vector<int> vi;
      for(int i = 1;i <= 5;i++){
          vi.push_back(i);
      }
      ```

    * ```c++
      #include<stdio.h>
      #include<vector>
      using namespace std;
      int main(){
          vector<int> vi;
          for(int i = 1;i <= 5;i++){
              vi.push_back(i);
          }
          vi.begin();//取vi得首元素地址
          vector<int>::iterator it = vi.begin();
          for(int i = 0;i < 5;i++){
              printf("%d",*(it + i));//输出vi[i]
              printf("%d",vi[i]);
          }
          return 0;
      }
      ```

    * `vi[i]和*(vi.begin() + i)`等价

    * `end()`是取尾元素地址的下一个地址

    * `begin()和end()`是左闭右开

      ```c++
      #include<stdio.h>
      #include<vector>
      using namespace std;
      int main(){
          vector<int> vi;
          for(int i = 1;i <= 5;i++){
              vi.push_back(i);
          }
          for(vector<int>::iterator it = vi.begin(); it != vi.end();it++){
              printf("%d",*it);
          }
          return 0;
      }
      ```

    * 只有在`vector`和`string`中，才允许使用`vi.begin() + 3`这种写法。

* vector常用函数

  * `push_back()`在vector后面添加元素
  * `pop_back()`删除vector的尾元素
  * `size()`计算vector的长度
  * `clear()`清空vector中的所有元素
  * `insert()`向vector的任意迭代器it处插入一个元素x`vi.insert(vi.begin() + 2,10);`将10插入到vi[2]位置
  * `erase()`删除单个元素、删除一个区间内的所有元素
    * 删除单个元素`vi.erase(vi.begin() + 3)`
    * 删除一个区间内的所有元素`erase(first,last)`，即删除`[first,last)`内的所有元素

#### set

* 内部自动有序且不含重复元素的容器

* 添加头文件`#include<set>`

* 定义一个set`set<int> name`

* set数组的定义`set<int> a[100]`

* set容器内元素的访问

  * 只能通过迭代器访问

    ```c++
    set<int>::iterator it;
    使用*it访问元素
    ```

    ```c++
    #include<stdio.h>
    #include<set>
    using namespace std;
    int main(){
        set<int> s;
        s.insert(3);//添加
        s.insert(4);
        for(set<int>::iterator it = s.begin();it != s.end();it++){
        	printf("%d",*it);
    	}
        return 0;
    }
    ```

* set的常用方法

  * insert(x)
  * find(value)返回set中对应值为value的迭代器
  * erase()
    * 删除单个元素
      * s.erase(s.find(3))//找到并删除
    * 删除所需要删除元素的值
      * s.erase(value)
    * 删除一个区间内的所有元素
      * s.erase([first,last))
      * set<int>::iterator it = s.find(30);
      * s.erase(it,s.end())//删除30至set末尾之间的元素
  * s.clear()清空所有元素
  * s.size()

#### string

* 添加头文件`#include<string>`

* 定义`string str`

* 初始化`string str = "abcd"`

* 访问内容

  * 通过下标访问`str[i]`

  * `printf("%s\n",str.c_str());`输出整个字符串

  * 通过迭代器访问

    ```c++
    for(string::iterator it = str.begin();it != str.end();it++){
    		printf("%c\n",*it);
    	}
    ```

    ```c++
    支持str.begin() + 3
    str.insert(str.begin() + 2,'d');
    ```

* operator+=：将两个string直接拼接起来

  ```c++
  string str1 = "abc";
      string str2 = "def";
      string str3;
      str3 = str1 + str2;		//拼接起来，赋值给str3
      str1 += str2;	//直接拼接在str1上
  ```

* 比较符`==`、`！=`、`<`、`<=`、`>`、`>=`

  ```c++
  string str1 = "abc";
      string str2 = "def";
      string str3 = "aa";
  
  if(str1 < str3){
  	printf("ok1\n");
  }
  
  if(str1 != str2){
  	printf("ok2\n");
  }
      
  if(str1 >= str2){
  	printf("ok3\n");
  }
  ```

* `length()`和`size()`

* ```insert(pos,string)```

  ```c++
  str1.insert(2,str2);
  ```

* insert(it,it2,it3)：将串`[it2,it3)`插入到it位置上

  ```c++
  str1.insert(str1.begin(),str2.begin(),str2.end());
  ```

* `erase()`

  * 删除单个元素`str.erase(str.begin() + 4)`
  * 删除一个区间内的所有元素`str.erase(str.begin()+2,str.end()-1)`
  * `str.erase(pos,length)``str.erase(3,2)`

* `clear()`

* `substr(pos,len)`：返回从pos号位开始、长度为len的子串。

* `string::npos`：是一个常数，本身的值为-1，作为find函数失配时的返回值。

* `str.find(str2)`：当str2是str的子串时，返回其在str中第一次出现的位置，如果不是，返回-1.

* `str.find(str2,pos)`：从str的pos号位开始匹配str2

* `str.replace(pos,len,str2)`：把str从pos号位开始，长度为len的子串替换为str2.

* `str.replace(it1,it2,str2)`：把str的迭代器`[it1,it2)`范围的子串替换为str2。

  ```c++
  cout<<str1.replace(2,3,str3)<<endl;
  cout<<str1.replace(str1.begin(),str1.begin() + 3,str3)<<endl;
  ```

#### map

* 定义

  * `map<string,int> mp`; 第一个是键的类型，第二个是值的类型
  * `map<set<int>,string> mp`

* map容器内元素的访问

  * 通过下标访问`map中的键是唯一的`

    ```c++
    #include<iostream>
    #include<map>
    using namespace std;
    int main(){
    	map<char,int> mp;
    	mp['c'] = 20;
    	mp['c'] = 30;
    	
    	printf("%d\n",mp['c']);
    	return 0;
    }
    ```

  * 通过迭代器访问

    ```c++
    map<string,int>::iterator it
    #include<iostream>
    #include<map>
    using namespace std;
    int main(){
    	map<char,int> mp;
    	mp['a'] = 20;
    	mp['b'] = 30;
    	mp['c'] = 40;
    	for(map<char,int>::iterator it = mp.begin();it != mp.end();it++){
    		printf("%c %d\n",it->first,it->second);
    	}
    	printf("%d\n",mp['c']);
    	return 0;
    }
    ```

    ##### map会以键从小到大的顺序自动排序

* 常用函数

  * `find(key)`

    ```c++
    map<char,int>::iterator it = mp.find('a');
    cout<<it->first<<it->second<<endl;
    ```

  * `erase()`

    * 删除单个元素
      * `mp.erase(it)`
    * 删除一个区间内的所有元素
      * `mp.erase(mp.begin()+1,mp.end())`

  * `size()`

  * `clear()`

#### queue

* 定义

  * `queue<int> name`

* 访问容器内元素

  * `front()`访问队首元素，`back()访问队尾元素`

    ```c++
    #include<stdio.h>
    #include<queue>
    using namespace std;
    int main(){
    	queue<int> q;
    	for(int i = 1;i <= 5;i++){
    		q.push(i);
    	}
    	
    	printf("%d %d\n",q.front(),q.back());
    	return 0;
    }
    ```

* 常用方法

  * `push(x)`：入队
  * `front()`、`back()`：队首，队尾元素
  * `pop()`：出队
  * `empty()`：检测queue是否为空
  * `size()`：元素个数

#### priority_queue(优先队列)

* 队首元素都是优先级最大的

* 定义

  * `priority_queue<int> name`

* 访问元素

  * `top()`访问队首元素

* 常用函数

  * `push(x)`：入队
  * `top()`：访问队首元素
  * `pop()`：出队
  * `empty()：`判断是否为空
  * `size()`

* 优先级设置

  * `priority_queue<int> q`

  * `priority_queue<int,vector<int>,less<int>> q`

    * `less<int>`：表示数字大的优先级越大，`greater<int>`表示数字小的优先级越大。

  * 结构体的优先级设置

    * ```c++
      struct fruit{
          string name;
          int price;
          
          friend bool operator<(fruit f1,fruit f2){
              return f1.price < f2.price;
          }
      };
      
      priority_queue<fruit> q;
      ```

      ```c++
      #include<iostream>
      #include<string>
      #include<queue>
      using namespace std;
      struct fruit{
          string name;
          int price;
          
          friend bool operator < (fruit f1,fruit f2){
              return f1.price > f2.price;
          }
      }f1,f2,f3;
      
      int main(){
          priority_queue<fruit> q;
          f1.name = "桃子";
          f1.price = 3;
          
          f2.name = "梨子";
          f2.price = 4;
          
          f3.name = "苹果";
          f3.price = 1;
          
          q.push(f1);
          q.push(f2);
          q.push(f3);
          
          cout<<q.top().name<<" "<<q.top()<<endl;
          return 0;
      }
      ```

#### stack

*   添加头文件`#include<stack>`

* 定义
  * `stack<int> name`

* 访问元素

  ```c++
  #include<iostream>
  #include<stack>
  using namespace std;
  
  int main(){
      stack<int> st;
      for(int i=1;i<=5;i++){
      	st.push(i);
  	}
      printf("%d",st.top());
      return 0;
  }
  ```

* 常用函数

  * `push(x)`：入栈
  * `top()`：获取栈顶元素
  * `pop()`：出栈
  * `empty()`：判空
  * `size()`：获取元素个数

#### pair

* 将两个元素绑在一起作为一个合成元素。

* 添加头文件`#include<utility>`

* 定义

  * `pair<string,int> p`
  * 初始化`pair<string,int> p("haha",5)`
  * 临时构建一个pair`pair<string,int>("haha",5)`或`make_pair("haha",5)`

* 访问元素

  ```c++
  #include<iostream>
  #include<utility>
  using namespace std;
  
  int main(){
      pair<string,int> p;
      p.first = "haha";
      p.second = 5;
      cout<<p.first<<" "<<p.second<<endl;
      
      p = make_pair("hehe",2);
      cout<<p.first<<" "<<p.second<<endl;
      
      p = pair<string,int>("huhu",1);
      cout<<p.first<<" "<<p.second<<endl;
      return 0;
  }
  ```

* 常用函数

  * `<`、`==`、`!=`、`<=`、`>=`：先以first的大小作为标准，只有当first相等时才判别second大小。

    ```c++
    #include<iostream>
    #include<utility>
    #include<map>
    #include<string>
    using namespace std;
    
    int main(){
    	map<string,int> mp;
    	mp.insert(make_pair("heihei",5));
    	mp.insert(pair<string,int>("haha",10));
    	for(map<string,int>::iterator it = mp.begin();it != mp.end();it++){
    		cout<<it->first<<" "<<it->second<<endl;
    	}
        return 0;
    }
    ```

#### algorithm头文件下的常用函数

* `#include<algorithm>`

* `max(x,y)、min(x,y)`：返回x和y中的最大值和最小值。返回三者 的最大值`max(x,max(y,z))`。

* `abs(x)`：x的绝对值，x必须是整数，浮点型绝对值用math 头文件下的`fabs()`。

* `swap(x,y)`：交换x和y的值。

* `reverse(it,it2)`：将数组指针在`[it,it2)`之间的元素或容器的迭代器在`[it,it2)`范围内的元素进行反转。

  ```c++
  int a[10] = {1,2,3,4,5,6};
  	reverse(a,a+6);
  	for(int i = 0;i < 6;i++){
  		cout<<a[i]<<" ";
  	}
  ```

  * 对容器中的元素进行反转。

    ```c++
    string str = "abcdefg";
    	reverse(str.begin(),str.end());
    	for(int i = 0;i < str.length();i++){
    		cout<<str[i]<<" ";
    	}
    ```

* `next_permutation()`：给出一个序列在全排列中的下一个序列。

  ```c++
  int b[10] = {1,2,3,4,5};
  	do{
  		printf("%d%d%d%d%d\n",b[0],b[1],b[2],b[3],b[4]);
  	}while(next_permutation(b,b+5));
  ```

* `fill()`：把数组或容器中的某一段区间赋为某个相同的值。

* `sort(首元素地址[必填]，尾元素地址的下一个地址[必填]，比较函数[非必填])`：递增排序

  ```c++
  int c[5] = {9,2,5,-1,6};
  	sort(c,c+5); 
  	for(int i = 0;i < 5;i++){
  		cout<<c[i]<<" ";
  	}
  ```

  * 从大到小排序

    ```c++
    #include<iostream>
    #include<algorithm>
    #include<string>
    using namespace std;
    
    bool cmp(int a,int b){
    		return a > b;	//当a>b时，把a放在b前面 
    	}
    	
    int main(){
    	
    	int a[] = {3,1,4,2};
    	sort(a,a+4,cmp);
    	for(int i = 0;i < 4;i++){
    		cout<<a[i]<<" ";
    	} 
        return 0;
    }
    ```

  * 对结构体数组的排序

    ```c++
    #include<iostream>
    #include<algorithm>
    #include<string>
    using namespace std;
    
    struct node{
    	int x,y;
    }ssd[10];
    
    bool cmp(node a,node b){
    		return a.x > b.x;	//从大到小排序
    	}
    	
    int main(){
    	
    	ssd[0].x = 2;
    	ssd[0].y = 2;
    	
    	ssd[0].x = 1;
    	ssd[0].y = 3;
    	
    	ssd[0].x = 3;
    	ssd[0].y = 1;
    	
    	sort(ssd,ssd+3,cmp);
    	for(int i = 0;i < 3;i++){
    		cout<<ssd[i].x<<" "<<ssd[i].y<<endl;
    	}
        return 0;
    }
    ```

  * 容器的排序(只有vector、string、queue是可以使用sort的)

    ```c++
    #include<iostream>
    #include<algorithm>
    #include<vector>
    using namespace std;
    
    bool cmp(int a,int b){
    		return a > b;	//当a>b时，把a放在b前面 
    	}
    	
    int main(){
    	
    	vector<int> vi;
    	vi.push_back(3);
    	vi.push_back(1);
    	vi.push_back(2);
    	
    	sort(vi.begin(),vi.end(),cmp);	//对整个vector排序
    	
    	for(int i = 0;i < 3;i++){
    		cout<<vi[i]<<" ";
    	} 
        return 0;
    }
    ```

* `lower_bound()`和`upper_bound()`：需要用在一个有序数组或容器中。

  * `lower_bound(first,last,val)`：用来寻找在数组或容器的`[first,last)`范围内第一个值大于等于val的元素的位置，如果是数组，则返回该位置的指针；如果是容器，则返回该位置的迭代器。

  * `upper_bound(first,last,val)：`用来寻找在数组或容器的`[first,last)`范围内第一个值大于等于val的元素的位置，如果是数组，则返回该位置的指针；如果是容器，则返回该位置的迭代器。

  * 如果数组或容器中没有需要寻找的元素，则返回可以插入该元素的位置的指针或迭代器。

    ```c++
    #include<iostream>
    #include<algorithm>
    #include<vector>
    using namespace std;
    
    int main(){
    	
    	int a[10]={1,2,2,3,3,3,5,5,5,5};
    	
    	//寻找-1 
    	int* lowerPos = lower_bound(a,a+10,-1);
    	int* upperPos = upper_bound(a,a+10,-1);
    	cout<<lowerPos - a<<" "<<upperPos - a<<endl;
    	
    	//寻找1
    	lowerPos = lower_bound(a,a+10,1);
    	upperPos = upper_bound(a,a+10,1);
    	cout<<lowerPos - a<<" "<<upperPos - a<<endl;
    	
    	//寻找3
    	lowerPos = lower_bound(a,a+10,3);
    	upperPos = upper_bound(a,a+10,3);
    	cout<<lowerPos - a<<" "<<upperPos - a<<endl;
    	
    	//寻找4
    	lowerPos = lower_bound(a,a+10,4);
    	upperPos = upper_bound(a,a+10,4);
    	cout<<lowerPos - a<<" "<<upperPos - a<<endl;
    	
    	//寻找6
    	lowerPos = lower_bound(a,a+10,6);
    	upperPos = upper_bound(a,a+10,6);
    	cout<<lowerPos - a<<" "<<upperPos - a<<endl;
    	
    	return 0;
    }
    ```

  * 获得 元素下标，可以不使用指针。

    ```c++
    #include<iostream>
    #include<algorithm>
    #include<vector>
    using namespace std;
    
    int main(){
    	int a[10]={1,2,2,3,3,3,5,5,5,5};
    	cout<<lower_bound(a,a+10,3) - a<<" "<<upper_bound(a,a+10,3) - a<<endl;
    	return 0;
    }
    ```



