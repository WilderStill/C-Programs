#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,l,r;
int ans[111];
bool vis[111];
pair<int,int>qp[111];
bool check(int a,int b)
{
	if(qp[a].first!=qp[b].first)return qp[a].first<qp[b].first;
	return qp[a].second<qp[b].second;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&qp[i].first,&qp[i].second);
	qp[0]={0x3f3f3f3f,0x3f3f3f3f};
	for(int i=1;i<=n;++i)
	{
		int pos=0;
		for(int j=1;j<=n;++j)
			if(!vis[j]&&check(j,pos))pos=j;
		ans[pos]=qp[pos].first;
		vis[pos]=1;
		pos=ans[pos]+1;
		for(int j=1;j<=n;++j)
			if(qp[j].first<pos)
				qp[j].first=pos;
	}
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
	return 0;
}
