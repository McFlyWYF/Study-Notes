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