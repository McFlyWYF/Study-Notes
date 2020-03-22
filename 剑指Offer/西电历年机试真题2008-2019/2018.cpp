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

//2018-C
#include<iostream>
#include<set>
#include<utility>	//pair 
using namespace std;
set<pair<int,int> > pot;	//pair��һ��ֵ��ϳ�һ��ֵ ,set�е�Ԫ�ز����� �� 
int main()
{
	int n,x1,x2,y1,y2;
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>x1>>y1>>x2>>y2;
		for(int i = x1;i < x2;i++){
			for(int j = y1;j < y2;j++){
				pot.insert(make_pair(i,j));	// ��i��j��ֵ����һ���µ�pair����
											//��Ԫ�����ͷֱ���i��j�����͡�
			}
		}
	}
	
	cout<<pot.size()<<endl;
	return 0;	
}

//2018-D 
#include<iostream>
#include<string>
using namespace std;

typedef struct{
	string date;
	int grade;
}student;

int main()
{
	int n;
	cin>>n;
	string date;
	int grade;

	student s1[n];
	
	//������� 
	for(int i = 0;i < n;i++){
		cin>>date;
		cin>>grade;

		s1[i].date = date;
		s1[i].grade = grade;
	}

	//ð������  
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n - i - 1;j++){
			if(s1[j].grade < s1[j+1].grade){	//�ɼ����Ӵ�С���� 
				swap(s1[j].grade,s1[j+1].grade);
				swap(s1[j].date,s1[j+1].date);
			}
			
			if(s1[j].grade == s1[j+1].grade){		//�ɼ���ȣ������ڴ�С�������� 
				if(s1[j].date.compare(s1[j+1].date) == 1){
					swap(s1[j].date,s1[j+1].date);
				}
			}
		}
	}
	//��ӡ 
	for(int i = 0;i < n;i++){
		cout<<s1[i].date<<" "<<s1[i].grade<<endl;
	}
	return 0;
}
