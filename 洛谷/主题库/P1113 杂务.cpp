#include<bits/stdc++.h>
using namespace std;
vector<int> g[2000005];
int n,tim[2000005],f[2000005],k,v,ans=0,d[2000005];
queue<int> que;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>v>>tim[i];
		while(1)
		{
			cin>>k;
			if(k==0)	break;
			g[k].push_back(v);
			d[v]++;
		}
	}
	
	for(int i=1;i<=n;i++)//n个点，输出每个点的邻居 
	{
		f[i]=tim[i];
		if(d[i]==0)que.push(i);
	}
	while(!que.empty())
	{
		int head=que.front();
		que.pop();
		for(int i=0;i<g[head].size();i++)
		{
			v=g[head][i];
			d[v]--; 
			f[v]=max(f[v],f[head]+tim[v]);
			if(d[v]==0)que.push(v);
		}
	}
	for(int i=1;i<=n;i++)//n个点，输出每个点的邻居 
	{
		ans=max(ans,f[i]);
	}
	cout<<ans;
 	return 0;
}
