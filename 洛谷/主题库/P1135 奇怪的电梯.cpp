#include<bits/stdc++.h>
#define M 114514
using namespace std;
queue<pair<int,int> >q;
pair<int,int>siu[M];
int k[M],n,a,b;
bool vis[M];
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++)scanf("%d",&k[i]),siu[i]=make_pair(i+k[i],i-k[i]);
	q.push(make_pair(a,0));
	while(!q.empty())
	{
		int x=q.front().first,y=q.front().second;
		q.pop();
		if(x==b){printf("%d",y);return 0;}
		if(siu[x].first<=n&&!vis[siu[x].first])vis[siu[x].first]=1,q.push(make_pair(siu[x].first,y+1));
		if(siu[x].second>0&&!vis[siu[x].second])vis[siu[x].second]=1,q.push(make_pair(siu[x].second,y+1));
	}
	printf("-1");
	return 0;
}
