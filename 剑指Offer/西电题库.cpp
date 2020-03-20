/* 
#include<iostream>
#include<map>
using namespace std;

//2013-12-1 
int main()
{
	map<int,int> m;
	int n;
	int num;
	cin>>n;
	//构建map 
	for(int i = 0;i < n;i++){
		cin>>num;
		m[num]++;
	}	
	//找出出现次数最多的数
	int ans,count = 0; 
	for(map<int,int>::iterator it = m.begin();it != m.end();it++){
		if(it->second > count){
			count = it->second;
			ans = it->first;
		}
	}
	cout<<ans<<endl;	
	return 0;
} 



//2013-12-2 
#include<string>
int main()
{
	string s1;
	cin>>s1;
	cout<<"输入的ISBN号码是："<<s1<<endl;
	int j = 1;
	int sum = 0;
	int shibie = 0;
	int shibiema;
	//计算识别码 
	for(int i = 0;i < s1.size() - 1;i++){
//		cout<<s1[i]<<" ";
		if(s1[i] != '-'){
			sum += (s1[i] - '0') * j++;
		}
	}
//	cout<<sum<<endl;
	shibie = sum % 11;
	if(shibie == 10){
		shibie = 'X' - '0';
	}
	cout<<"正确的识别码是："<<shibie<<endl;
	shibiema = s1[s1.size() - 1] - '0';//取最后一位识别码，转为数字 ：-'0' 
//	cout<<shibiema<<endl;
	if(shibiema == shibie){
		cout<<"Right"<<endl;
	}else{
		s1[s1.size() - 1] = '0' + shibie;//将最后一位改为正确的识别码 ：+'0' 
		cout<<s1<<endl;
	}	
	return 0;
}


//2013-12-3 
#include<stack> 
int main()
{
	int n;
	cin>>n;
	int h[n];	//高 
	int area1[((1+n)*n) / 2];	//存放所以组合的面积 
	int k = 0;
	int min;	//每个组合中的最小数字 
	int area = 0;	//每个组合的面积 
	
	for(int i = 0;i < n;i++){
		cin>>h[i];
	}
	
	int z = 1;	//底边长度 
	
	for(int i = 0;i < n;i++){
		min = h[i];
		for(int j = i;j < n;j++){
			if(h[j] < min){
				min = h[j];
			}
			area = min * (z++);
			area1[k++] = area;
		}
		z = 1;
	}
	
//	for(int i = 0;i < ((1+n)*n) / 2;i++){
//		cout<<area1[i]<<" ";
//	}
	
	int maxarea = 0;
	for(int i = 0;i < ((1+n)*n) / 2;i++){
		if(area1[i] > maxarea){
			maxarea = area1[i];
		}
	}
	
	cout<<"最大矩形面积是："<<maxarea<<endl;
	return 0;
}
#include<map>
int main()
{
	int n;
	map<int,int> a;
	int count = 0;
	cin>>n;
	int m;
	
	for(int i = 0;i < n;i++){
		cin>>m;
		if(m < 0){
			m = (-1)*m;
		}
		a[m]++;
	}
	
	for(map<int,int>::iterator it = a.begin();it != a.end();it++){
		if(it->second == 2){
			count++;
		}
	}
	
	cout<<count<<endl;
	return 0;
}


#include<cstring>
const int  N = 1000;
int main()
{
	int flag[N*2+1];
	int n,v,sum = 0,minus;
	//变量初始化
	memset(flag,0,sizeof(flag)); 
	
	//输入数据
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>v;
		
		//值映射 0 - 2000
		minus = N - v;		//负值映射 
		v += N;		//正值映射
		
		if(flag[minus] == 1){
			sum++;
		} 
		
		flag[v] = 1;
		 
	} 
	
	cout<<sum<<endl;
	return 0;
}
*/




/*

//2008-A

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	int a[100];
	int flag = 1;
	int k = 0;
	
	while(cin>>n){
		if(n != 0){
			for(int i = 0;i < n;i++){
			cin>>a[i];
		}
	
		sort(a,a+n);		//排序 
		
		while(k < n - 2 && flag){
			if((a[k+1] - a[k]) == (a[k+2] - a[k+1])){
				flag = 1;
			}else{
				flag = 0;
				break;
			}
			k++;
		}
		
		if(flag == 1){
			cout<<"yes"<<endl;
		}
		if(flag == 0){
			cout<<"no"<<endl;
		}
		
		flag = 1;
		}
		if(n == 0){
			exit(0);
		}
		
	}
	return 0;	
}
*/

/*
//2008-B
#include<iostream>
using namespace std;
int main()
{
	int n;
	
	int p,q,r;
	
	while(cin>>n){
		if(n != 0){
			p = n / 100;
			q = (n % 100) / 10;
			r = (n % 100) % 10;
			
			if(p*p*p + q*q*q + r*r*r == n){
				cout<<"yes"<<endl;
			}else{
				cout<<"no"<<endl;
			}		
		}
		
		if(n == 0){
			exit(0);
		}
	}
	return 0;	
} 
*/

/* 
//2008-C
#include<iostream>

using namespace std;

int main() {
	int i, j, n, count, index, a, b, ta, tb;
	while (true) {
		cin >> n;
		if (n == 0)		//退出 
			return 0;
		if (n <= 2 || n > 10)
			continue;
		index = 0;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				ta = i;		//赋值 
				tb = j;
				count = 0;	//计数器 
				do {
					a = (ta + tb) % n;     //i' 
					b = (ta + 2 * tb) % n;		//j'
					ta = a;
					tb = b;
					count++;
					if (a == i&&b == j) {
						index = index > count ? index : count;
						break;
					}
				} while (count <= n*n / 2);
			}
		}
		cout << index << endl;

	}
	return 0;
}

*/


/*
//2008-D
#include<iostream>
using namespace std;

//判断是否为质数 
int zhishu(int n)
{
	for(int i = 2;i < n;i++){
		if(n % i ==0){
			return 0;
		}
	}	
	
	return 1;
}

//求各位和 
int geweisum(int n)
{
	int p = 0;
	while(n != 0){
		p+= n % 10;
		n = n / 10; 
	}
	return p;
}


int main()
{
	int n,t;
	int sum = 0;//各位和 
	while(cin>>n){
		if(n != 0){
			t = n;
			while(t > 1){
				for(int i = 2;i <= t;i++){
					if(t % i == 0 && zhishu(i) == 1){	//t能被i整数并且i为质数 
						sum += geweisum(i);		//质因数各位求和 
						t = t / i;		 
					}
					
			}
		}
		
		if(sum == geweisum(n)){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}
		
		}
		if(n == 0){
			exit(0);
		}
	}
	return 0;
}

*/

/* 
//2008-E
#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

void f(int a[], int x, int n)       //函数用于计算x的n次方，存入a[]数组
{
	int temp = 0;
	while (n--)
	{
		for (int i = 0; i != 400; i++)
		{
			temp += a[i] * x;  //
			a[i] = temp % 10;
			temp /= 10;
		}
	}
}
int main()
{
	char a[10];            //保存输入的一行
	int n = 0;               //阶数
	int dot = 0;             //存点的位置
	while (gets(a))
	{
		for (dot = 0; a[dot] != '.'; dot++);     //找到小数点的位置
		int q = 0;
		for (q = 5; a[q] == '0'; q--);           //找到最后一个非零数的位置
		int num = q - dot;                    //num保存小数点后的有效位数

		int sum = 0;                        //将输入的小数转化为整数
		for (int i = 0; i <= q; i++)
		{
			if (a[i] >= '0'&&a[i] <= '9')
				sum = sum * 10 + a[i] - '0';
		}
		if (sum == 0)                       //由于0的n次方比较特殊，单独拿出来了
		{
			cout << "0" << endl;
			continue;
		}
		if (a[7] == ' ')                    //计算n
			n = a[8] - '0';
		else
			n = (a[7] - '0') * 10 + a[8] - '0';
		num *= n;                           //计算需要点点的位数
		int ans[400] = { 1 };                  //保存结果
		f(ans, sum, n);
		int last = 0;
		for (last = 399; ans[last] == 0 && last != num - 1; last--);   //找到输出的起始位置
		for (; last != -1; last--)
		{
			if (last == num - 1)
			{
				cout << ".";
			}
			cout << ans[last];
		}
		cout << endl;
	}
	return 0;
}
*/

/*
//2009-A
#include<iostream>
using namespace std;
int main()
{
	int a,b;
	
	cin>>a;
	cin>>b;
	if(a >= 1 && b < 100000){
		for(int i = a+1;i <= b;i++){
			int sum = 0;
			for(int j = 1;j < i;j++){
				if(i % j == 0){
					sum = sum + j;
				}
			}
			if(i == sum){
				cout<<i<<endl;
			}
		}
	}
	
	return 0;
}
*/

/* 
//2009-B
#include<iostream>
#include<algorithm>
using namespace std;

//从大到小排序 
bool cmp(int x,int y)
{	
	return x > y;
}
    
int main()
{
	int m;
	cin>>m;
	int a[m][m];
	int b[2*m + 2];
	int k = 0;
	for(int i = 0;i < m;i++){
		for(int j = 0;j < m;j++){
			cin>>a[i][j];
		}
	}
	
	//每一行 
	for(int i = 0;i < m;i++){
		int sum = 0;
		for(int j = 0;j < m;j++){
			sum += a[i][j];
		}
		b[k++] = sum;
	}
	
	//每一列 
	for(int i = 0;i < m;i++){
		int sum = 0;
		for(int j = 0;j < m;j++){
			sum += a[j][i];
		}
		b[k++] = sum;
	}
	
	//主对角线 
	int sum1 = 0;
	for(int i = 0;i < m;i++){
	
		sum1 += a[i][i];
	}
	b[k++] = sum1;
	
	//副对角线 
	int c = 0,d = m-1;
	int sum2 = 0;
	while(c < m){
		sum2 += a[c++][d--];
	}
	b[k++] = sum2;
    
	sort(b,b + k,cmp);
	
	for(int i = 0;i < k;i++){
		cout<<b[i]<<" ";
	} 
	
	return 0;
}
*/

/*
//2009-C
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int m = 0;
	string s1;
	
	while(n > 0){
		cin>>s1;
		n--;
		
		//取出其中的数字并拼接 
		for(int j = 0;j < s1.size();j++){
			if(s1[j] >= '0' && s1[j] <= '9'){
				m = m * 10 + (s1[j] - '0');
			}
		}
		
		int max = 0;
		
		//如果数字是0，则输出0 
		if(m == 0){
			max = 0;
		}
		
		//查找最大的公因子 
		for(int j = 1;j < m;j++){
			
			if(m % j == 0){
				max = j;
			}	
		}
		
		//如果是素数，那么最大公因子是本身 
		if(max == 1){
			max = m;
		}
		
		cout<<max<<" "<<endl;	
	}
	
	return 0;
}
*/

/*
//2009-D
#include<iostream>
using namespace std;

struct node {  //二叉树定义
	char value;
	node* lchild;
	node* rchild;
	node(char ch) {
		value = ch;
		lchild = rchild = NULL;
	}
};

//建立二叉树 
node* buildTree(string pre, string in) {
	int len = pre.size();
	if (len <= 0) return NULL;
	node* root = new node(pre[0]);
	int p = in.find(pre[0]);
	root->lchild = buildTree(pre.substr(1, p), in.substr(0, p));
	root->rchild = buildTree(pre.substr(p + 1, len - p - 1), in.substr(p + 1, len - p - 1));
	return root;
}


void postOrder(node* root) {   //后序遍历
	if (root->lchild) postOrder(root->lchild);
	if (root->rchild) postOrder(root->rchild);
	cout << root->value;
}

int main() {
	char pre[100], in[100];
	while (cin >> pre >> in) {
		node* root = buildTree(pre, in);
		postOrder(root);
		cout << endl;
	}
	return 0;
}
*/

/*
//2009-E
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
	string str1;
	cin>>str1;
	stack<char> s1;
		
		for(int i = 0;i < str1.size();i++){
			
			//遍历表达式，将左括号全部入栈 
			if(str1[i] == '(' || str1[i] == '[' || str1[i] == '{'){
				s1.push(str1[i]);
			}
			
			if(!s1.empty() && str1[i] == ')' && s1.top() == '('){
				s1.pop();
			}
			
			if(!s1.empty() && str1[i] == '}' && s1.top() == '{'){
				s1.pop();
			}
			
			if(!s1.empty() && str1[i] == ']' && s1.top() == '['){
				s1.pop();
			} 
		}
		
		//栈非空，输出no，否则输出yes 
		if(!s1.empty()){
			cout<<"no"<<endl;
		}else{
			cout<<"yes"<<endl;
		}
}
*/

/*
//2011-A
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int num;
	int b[n],a[n];
	int k = 0,j = 0;
	
	for(int i = 0;i < n;i++){
		cin>>num;
		a[i] = num;
	}
	
	for(int i = 0;i < n;i++){
		int sum = 0;
		while(a[i] != 0){
			
			sum += (a[i] % 10);
			a[i] = a[i] / 10;
		}
		
		b[k++] = sum;
	}
	
	sort(b,b+k);
	
	for(int i = 0;i < k;i++){
		cout<<b[i]<<" ";
	}
	
	return 0;
	
}
*/

/* 
//2011-B
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int m,n;
	cin>>m>>n;
	int a[m][n];
	int b[m];
	int c[n];
	int k = 0;
	
	//输入元素 
	for(int i = 0;i < m;i++){
		for(int j = 0;j < n;j++){
			cin>>a[i][j];
		}
	}
	
	//寻找每行的最小元素 
	for(int i = 0;i < m;i++){
		int min = a[i][0];
		
		for(int j = 0;j < n;j++){
			if(a[i][j] < min){
				min = a[i][j];
			}
		}
		b[i] = min;
	}
	
	//寻找每列的最大元素 
	for(int i = 0;i < n;i++){
		int max = a[0][i];
		
		for(int j = 0;j < m;j++){
			if(a[j][i] > max){
				max = a[j][i];
			}
		}
		c[i] = max;
	}

	//比较最小元素和最大元素是否相同，如果相同，则输出 
	for(int i = 0;i < m;i++){
		for(int j = 0;j < n;j++){
			if(b[i] == c[j]){
				cout<<i<<" "<<j<<" "<<b[i]<<endl;
			}
		}
	}
	
	return 0;
}
*/


