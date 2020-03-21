//2013-A
#include<iostream>
using namespace std;

int f(int n)
{	
	if(n == 0){
		return 7;
	}
	
	if(n == 1){
		return 11;
	}
		
	else{
		return f(n - 1) + f(n - 2); 
	}
}

int main()
{
	int n,m;
	cin>>n;
	
	for(int i = 0;i < n;i++){
		cin>>m;
		if(f(m) % 3 == 0){
			cout<<"yes"<<endl;
		}
		else{
			cout<<"no"<<endl;
		}
	}
	return 0;	
} 
 
//2013-B
#include<iostream>
#include<map>
#include<functional>

using namespace std;
int main()
{
	int a[20];
	map<int,int > mp;		//默认按键值升序排序 
	
	for(int i = 0;i < 20;i++){
		cin>>a[i];
		mp[a[i]]++;
	}

	for(map<int,int>::iterator it = mp.begin();it != mp.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
	
	return 0;
}

//2013-D
#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int main()
{
	int n;		//输入的数值 
	int m;		//输入数的进制 
	
	int z;
	cin>>z;
	for(int i = 0;i < z;i++){
		cin>>n>>m;
	
	string str;
	
	if(m == 10){
		int k = 0;
		while(n > 0){
		//取出每个数字 
			if(n % 2 == 0){
				str[k++] = '0';
			}
			if(n % 2 != 0){
				str[k++] = '1';
			}
			n = n / 2;
		}
		for(int i = k - 1;i >= 0;i--){
			cout<<str[i];
		}	
	}
	
	if(m == 2){
		int k = 0;
		while(n > 0){
			str[k++] = (n % 10) + '0';		//转换为字符存储 
			n = n / 10;
		}
		
		int sum = 0;
		for(int i = 0;i < k;i++){
			sum += (str[i] - '0') * pow(2,i);		//从右到左计算次方 
		}
		cout<<sum<<endl;
	}
	
	if(m == 0){
		cout<<0<<endl;	
	}
	}
	return 0;
}