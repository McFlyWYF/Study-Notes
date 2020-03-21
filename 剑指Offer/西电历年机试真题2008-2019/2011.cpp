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

//2011-C 
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str,str1;
	cin>>str;
	int k = 0;
	char a[100];
	
	for(int i = 0;i < str.size();i++){
		if(str[i] >= '1' && str[i] <= '9'){		//第一个数字 
			if(str[i+1] >= '0' && str[i+1] <= '9'){		//如果存在第二个数字 
				int n = (str[i] - '0') * 10 + (str[i+1] - '0');
				for(int j = 0;j < n - 1;j++){
					a[k++] = str[i - 1];
				}
			}else{				//只存在一个数字 
				int n = str[i] - '0';
				for(int j = 0;j < n - 1;j++){
					a[k++] = str[i - 1];
				}
			}
			
		}else{
			a[k++] = str[i];		//不是数字直接赋值 
		}
	}
	for(int i = 0;i < k;i++){
		cout<<a[i];
	}
	
	return 0;
} 

//2011-D
#include<iostream>
#include<queue>
#include<vector>
#include<functional>   //greater

using namespace std;

priority_queue<int ,vector<int>, greater<int> > q;

int main() {
	int n;
	cin>>n;
	//将输入元素存入栈中 
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		q.push(x);
	}
	int ans = 0;		//带权路径长度 
	while (q.size() > 1) {		//至少存在两个元素 
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();
		ans += a + b;
		q.push(a + b);
	}
	cout << ans << endl;
		 
	return 0;
}