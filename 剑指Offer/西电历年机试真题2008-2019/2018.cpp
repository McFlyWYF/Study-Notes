//2018-A
#include<iostream>
using namespace std;
int main()
{
	int n,sum = 0,a = 0;
	
	while(~scanf("%d",&n) && n){
		if(n == 1){		//如果是1，加1 
			sum += 1;
			a = 1;		//将a置为1 
		}
		
		else if(a == 1 || a == 0){		//第一位是2或者1的下一位是2 
			sum += 2;
			a = 2;		
		}
		
		else {		//连续出现2 
			sum += a + 2;
			a = a + 2;
		}
	}
	
	cout<<sum<<endl;
	return 0;
}

//2008-B
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int m,n;	//m-大小写选项和n-行数 
	string str;		//子串 
	
	cin>>str>>m>>n;
	
	/*
	transform：
		参数（s.begin(), s.end(), s.begin(), toupper/tolower）;  
			s.begin()：起始范围
			s.end()：结束范围 
			s.begin()：转换后的直接赋值给s 
			toupper：全部转换为大写 
			tolower：全部转换为小写 
	*/
	
	
	if(m == 0){
		transform(str.begin(),str.end(),str.begin(),::tolower);		//将子串全部转为小写 
	}
	
	string T,tmp;	//T为匹配串,tmp的作用是作为中间变量，临时存储T 
	
	while(n--){
		cin>>T;
		
		/*
			resize()：设置大小 
		*/
		tmp.resize(T.size());	//将字符串的大小修改为匹配串的大小
		 
		if(m == 0){
			transform(T.begin(),T.end(),tmp.begin(),::tolower);		//将匹配串全部转为小写 
		}else{
			tmp = T;		//如果是1，直接赋值给T 
		}
		
		/*
			find()：返回值为目标字符的位置，没有找到返回npos 
		*/
		if(tmp.find(str,0) != string::npos){		//在匹配串中从下标0开始查找子串，如果找到，则输出 
			cout<<T<<endl;
		}
	}
	return 0;
}