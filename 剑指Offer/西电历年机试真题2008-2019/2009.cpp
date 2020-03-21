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