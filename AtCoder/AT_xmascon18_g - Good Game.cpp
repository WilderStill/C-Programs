#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		int m,n;//m��h��n��w 
		cin>>m>>n;
		if(m%2&&n%2)//��m��n��Ϊ����ʱ 
		{
			cout<<"First\n"<<m-1<<' '<<n-1<<'\n';//ѡ������
			while(true)
			{
				pair<int,int>p;
				cin>>p.first>>p.second;
				if(p.first==-1&&p.second==-1)break;
				int v=(p.first*n+p.second)^1;
				cout<<(v/n)<<' '<<(v%n)<<'\n';
			}
		}
		else if(m%2)//nΪż��ʱ
		{
			cout<<"Second\n";//ѡ����� 
			while(true)
			{
				pair<int,int>p;
				cin>>p.first>>p.second;
				if(p.first==-1&&p.second==-1)break;
				cout<<p.first<<' '<<(n-1-p.second)<<'\n';//�ͶԷ�����ͬһ�еĻ���λ���� 
			}	
		}
		else//mΪż��ʱ 
		{
			cout<<"Second\n";;//ѡ����� 
			while(true)
			{
				pair<int,int>p;
				cin>>p.first>>p.second;
				if(p.first==-1&&p.second==-1)break;
				cout<<(m-1-p.first)<<' '<<p.second<<'\n';//�ͶԷ�����ͬһ�еĻ���λ���� 
			}	
		}	
	}
	return 0;
}
