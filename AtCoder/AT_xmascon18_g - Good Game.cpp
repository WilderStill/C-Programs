#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		int m,n;//m即h，n即w 
		cin>>m>>n;
		if(m%2&&n%2)//当m和n都为奇数时 
		{
			cout<<"First\n"<<m-1<<' '<<n-1<<'\n';//选择先手
			while(true)
			{
				pair<int,int>p;
				cin>>p.first>>p.second;
				if(p.first==-1&&p.second==-1)break;
				int v=(p.first*n+p.second)^1;
				cout<<(v/n)<<' '<<(v%n)<<'\n';
			}
		}
		else if(m%2)//n为偶数时
		{
			cout<<"Second\n";//选择后手 
			while(true)
			{
				pair<int,int>p;
				cin>>p.first>>p.second;
				if(p.first==-1&&p.second==-1)break;
				cout<<p.first<<' '<<(n-1-p.second)<<'\n';//和对方放在同一行的互补位即可 
			}	
		}
		else//m为偶数时 
		{
			cout<<"Second\n";;//选择后手 
			while(true)
			{
				pair<int,int>p;
				cin>>p.first>>p.second;
				if(p.first==-1&&p.second==-1)break;
				cout<<(m-1-p.first)<<' '<<p.second<<'\n';//和对方放在同一列的互补位即可 
			}	
		}	
	}
	return 0;
}
