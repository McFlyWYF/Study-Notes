//2015-A
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	
	int sum = 0;
	
	for(int i = 0;i < n;i++){
		if(a[i] > 1){
			
			if(a[i] == 2){
				sum += a[i];
			}
				
			for(int j = 2;j < a[i];j++){		
				if(a[i] % j == 0){
					break;
				}
				if(j = a[i] - 1){
					sum += a[i];
				}
			}
		}		
	}
	cout<<sum<<endl;
	return 0;
}

//2015-B
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str,str1;
	cin>>str;
	int k = 0;
	
	int i = 0,count = 1;
	
	while(str[i] != '\0'){
		if(str[i] >= 'A' && str[i] <= 'Z' && str[i+1] != str[i]){	//前一位和后一位不相等 
			if(count >= 2){		//字符大于2计数 
				str1[k++] = str[i];		//字符赋值 
				str1[k++] = count + '0';		//数字赋值 
				i++;		//移到下一位 
				count = 1;		//计数器清零 
			}
			else{
				str1[k++] = str[i];		//字符等于1，不加数字 
				i++;
				count = 1;
			}
			
		}
		
		if(str[i] >= 'A' && str[i] <= 'Z' && str[i+1] == str[i]){		//下一位和前一位相同，移到下一位，计数器加一 
			i++;
			count++;
		}
	}
	//打印 
	for(int i = 0;i < k;i++){
		cout<<str1[i];
	}
	
	return 0;
}