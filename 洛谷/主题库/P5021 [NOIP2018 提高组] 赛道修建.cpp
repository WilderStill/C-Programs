#include<bits/stdc++.h>
#define M 11451411 
#define ll long long
using namespace std;
int n,m;
struct enode
{
	int to,nxt,val;
}edge[M<<1];
int hd[M],tot;
void addedge(int u,int v,int w)
{
	edge[++tot].to=v;
	edge[tot].val=w;
	edge[tot].nxt=hd[u];
	hd[u]=tot;
}
bool vis[M];
int dia,f[M];
void dfs_dia(int pos)
{
	vis[pos]=1;
	for(int i=hd[pos];i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(vis[v])continue;
		dfs_dia(v);
		dia=max(dia,f[pos]+f[v]+edge[i].val);
		f[pos]=max(f[pos],f[v]+edge[i].val);
	}
}
struct node
{
	int cnt,id;
	node(int _cnt,int _id){cnt=_cnt,id=_id;}
};
bool fg;
node dfs_check(int x,int fa,int pos)
{
	int cnt=0,id=0;
	multiset<int>mset;
	for(int i=hd[x];i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(v==fa)continue;
		node tp=dfs_check(v,x,pos);
		if(edge[i].val+tp.id>=pos)++cnt;
		else mset.insert(edge[i].val+tp.id);
		cnt+=tp.cnt;
	}
	while(!mset.empty())
	{
		auto it=mset.upper_bound(0);
		int top=*it;
		mset.erase(it);
		it=mset.lower_bound(pos-top);
		if(it==mset.end())id=top;
		else mset.erase(it),++cnt;
	}
	if(cnt>=m)fg=1;
	return node(cnt,id);
}
int ans;
int main()
{
	srand(time(0));
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<n;++i)
	{
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w),addedge(v,u,w);
	}
	dfs_dia(1);
	int l=0,r=dia;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		fg=0;
		dfs_check(1,0,mid);
		if(fg)l=mid+rand()%2,ans=mid;
		else r=mid-rand()%2;
	}
	printf("%d",ans);
	return 0;
}
