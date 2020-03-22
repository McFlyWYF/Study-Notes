//2019-A
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	int count = 1;	//������ 
	
	//�������� 
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	
	
	for(int i = 0;i < n;i++){
	//���ǰһλ�ͺ�һλ����ȣ�������+1 ��i != n -1��ֹԽ�� 
		if((a[i] != a[i+1]) && (i != n - 1)){
			count++;
		}
	//���ǰһλ�ͺ�һλ��ȣ�������һλ 
		if((a[i] == a[i+1]) && (i != n - 1)){
			continue;
		}
	}
	
	cout<<count<<endl;
	return 0;
} 

//2019-B
#include<iostream>
#include<map>
#include<algorithm>
#include<vector> 
using namespace std;

//�ȽϺ������Ӵ�С��� 
bool cmp(pair<int,int> a,pair<int,int> b){
	return a.second > b.second;
}

int main()
{
	int n,m,k;
	cin>>n;
	
	map<int,int> mp;
	
	for(int i = 0;i < n;i++){
		cin>>m;
		k = m;		//�ݴ�������ֵ 
		int sum = 0;	//��λ���ֺ� 
		
		while(m > 0){
			sum += m % 10;
			m = m / 10;
		}
		
		mp.insert(pair<int,int> (k,sum));	//�����ֺ͸�λ�Ͳ���map�� 
	}
	
	vector< pair<int,int> > vec(mp.begin(),mp.end());	//��map�е�Ԫ�ش洢�������У���Ϊsort����ֻ�ܶ������vector���� 
	sort(vec.begin(),vec.end(),cmp);	//��value���Ӵ�С���� 
	
	for(int i = 0;i < vec.size();i++){
		printf("%d %d\n",vec[i].first,vec[i].second);	//��ӡ 
	}
	return 0;
}

//2019-C
#include<iostream>
#define MAXN 35
using namespace std;

int main(){
	
	int board[MAXN][MAXN];
	int left[MAXN][MAXN];	//ͳ���� 
	int up[MAXN][MAXN];		//ͳ���� 
	int n,m;

    cin>>n>>m;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin>>board[i][j];
            left[i][j] = up[i][j] = 1;
            if(j > 0 && board[i][j] == board[i][j-1]){
            	 left[i][j] = left[i][j-1] + 1;		//ÿ��ǰһ��Ԫ�غͺ�һ��Ԫ����ͬ 
			}
            if(i > 0 && board[i][j] == board[i-1][j]){ 
            	up[i][j] = up[i-1][j] + 1;		//ÿ��ǰһ��Ԫ�غͺ�һ��Ԫ����ͬ 
			}
        }
    }
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(left[i][j] >= 3){	//���ͳ�Ƶ��е�ÿ��Ԫ�ظ������ڵ���3������λǰleft[i][j]Ԫ����0 
                for(int k = 0;k < left[i][j];k++)
                    board[i][j-k] = 0;	
            }
            if(up[i][j] >= 3){
                for(int k = 0;k < up[i][j];k++)
                    board[i-k][j] = 0;
            }
        }
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

//2019-D
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	stack<char> s;
	stack<int> data;
	
	string str;
	cin>>str;
	
	while(!s.empty()){
		s.pop();
	}
	
	while(!data.empty()){
		data.pop();
	}
	for(int k = 0;k < str.size();k++){
		cout<<str[k];
	}
	
	cout<<endl;
	
	int i = 0;
	while(str[i] != '\0'){
		if(str[i] >= '0' && str[i] <= '9'){
			data.push(str[i] - '0');
			i++;
		}
		
		else if(str[i] == '+'){
			s.push(str[i]);
			i++;
		}
		
		else if(str[i] == '-'){
			data.push((str[i+1] - '0') * (-1));
			s.push('+');
			i += 2;
		}
		
		else if(str[i] == 'x'){
			int aa = data.top();
			data.pop();
			data.push(aa * (str[i+1] - '0'));
			i += 2;
		}
		
		else if(str[i] == '/'){
			int aa = data.top();
			data.push(aa / (str[i+1] - '0'));
			data.pop();
			i += 2;
		}
	}
	
	while(!s.empty()){
		int aa = data.top();
		data.pop();
		int bb = data.top();
		data.pop();
		s.pop();
		data.push(aa + bb);
	}
	
	cout<<data.top()<<endl;
	
	return 0;
}
