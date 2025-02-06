#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
inline ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
	return x*f;
}
inline void write(ll x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
	return;
}
const int M=1e6+10;
struct node
{
	int nxt,to;ll val;
}edge[M<<1];
int tot,hd[M],ind[M];
bool kkk[M];
inline void addedge(int u,int v,ll w)
{
	edge[++tot].nxt=hd[u];
	edge[tot].to=v;
	edge[tot].val=w;
	hd[u]=tot;
	++ind[v];
	return;
}
int lcnt,cnt,pvis[M],id[M],cq[M];
ll ans1,ans2,dt[M],t1[M],t2[M];
bool cvis[M];
queue<int>tq;
inline bool pdfs(int u,int lst)
{
	if(pvis[u]==1)
	{
		pvis[u]=2,cvis[u]=1;
		id[++cnt]=u;
		return 1;
	}
	pvis[u]=1;
	for(int i=hd[u];i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		ll w=edge[i].val;
		if(i!=((lst-1)^1)+1&&pdfs(v,i))
		{
			if(pvis[u]==2)
			{
				t2[lcnt]=t2[lcnt+1]-w;
				return 0;
			}
			else id[++cnt]=u,cvis[u]=1,t2[cnt]=t2[cnt-1]+w;	
			return 1;
		}
	}
	return 0;
}
inline void dfs(int u)
{
	cvis[u]=1;
	for(int i=hd[u];i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		ll w=edge[i].val;
		if(cvis[v])continue;
		dfs(v);
		ans1=max(ans1,dt[v]+dt[u]+w);
		dt[u]=max(dt[u],dt[v]+w);
	}
}
inline void dp()
{
	int n=cnt-lcnt;
	for(int i=lcnt+1;i<=cnt;++i)
	{
		dfs(id[i]);
		t1[i+n]=t1[i]=dt[id[i]];
		t2[i+n]=t2[i+n-1]+t2[i]-t2[i-1];
	}
	int hd=0,tl=-1;
	for(int i=lcnt+1;i<=cnt+n;++i)
	{
		while(hd<=tl&&cq[hd]<=i-n)++hd;
		if(hd<=tl)ans2=max(ans2,t1[i]+t2[i]+t1[cq[hd]]-t2[cq[hd]]);
		while(hd<=tl&&t1[cq[tl]]-t2[cq[tl]]<=t1[i]-t2[i])--tl;
		cq[++tl]=i;
	}
}
signed main()
{
	int n=read();
	for(int i=1;i<=n;++i)
	{
		int u=i,v=read();ll w=read();
		addedge(u,v,w),addedge(v,u,w);
	}
	ll ans=0;
	for(int i=1;i<=n;++i)
		if(!cvis[i])
		{
			ans1=ans2=0,lcnt=cnt;
			pdfs(i,0),dp();
			ans+=max(ans1,ans2);
		}
	write(ans);
	return 0;
}
