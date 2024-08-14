#include<bits/stdc++.h>
#define M 11451411 
#define ll long long
using namespace std;
int n,m;
struct edge
{
	int to;
	int nxt;
	int val;
} e[M<<1];
int head[M],tot;
void add(int u,int v,int val)
{
	e[++tot].to=v;
	e[tot].nxt=head[u];
	e[tot].val=val;
	head[u]=tot;
}
bool vis[M];
int dia,dp[M];
void dm(int u)
{
	vis[u]=1;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int to=e[i].to;
		int val=e[i].val;
		if(vis[to]) continue;
		dm(to);
		dia=max(dia,dp[u]+dp[to]+val);
		dp[u]=max(dp[u],dp[to]+val);
	}
}
struct node
{
	int cnt,edge;
	node(int cnt1,int edge1)
	{
		cnt=cnt1;
		edge=edge1;
	}
};
int flg;
node dfs(int x,int fa,int bl)
{
	int cnt=0,edge=0;
	multiset<int> mset;
	for(int i=head[x];i;i=e[i].nxt)
	{
		int to=e[i].to;
		int val=e[i].val;
		if(to==fa)continue;
		node son=dfs(to,x,bl);
		if(val+son.edge>=bl)cnt++;
		else mset.insert(val+son.edge);
		cnt+=son.cnt;
	}
	while (!mset.empty())
	{
		multiset<int>::iterator it=mset.upper_bound(0);
		int top=*it;
		mset.erase(it);
		it=mset.lower_bound(bl-top);
		if (it == mset.end()) edge=top;
		else
		{
			mset.erase(it);
			++cnt;
		}
	}
	if (cnt >= m) flg=1;
	return node(cnt,edge);
}
int ans;
int main()
{
	srand((time)(0));
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,val;i<=n-1;i++)
	{
		scanf("%d%d%d",&u,&v,&val);
		add(u,v,val);
		add(v,u,val);
	}
	dm(1);
	int l=0,r=dia,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		flg=false;
		dfs(1,0,mid);
		if(flg)
		{
			l=mid+rand()%2;
			ans=mid;
		}
		else
		{
			r=mid-rand()%2;
		}
	}
	printf("%d",ans);
	return 0;
}
