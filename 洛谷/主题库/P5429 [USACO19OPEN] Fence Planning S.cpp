#include<bits/stdc++.h>
#define M 114514
#define C(a,b) 2*(a+b)
using namespace std;
int dot[5],ans=INT_MAX,n,m,son[M*2],nxt[M*2],head[M],tot;//dot[0,up,down,left,right]
bool vis[M];
void add(int x,int y)
{
	son[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
struct node
{
	int x,y;
}a[M];
void dfs(int st)
{
	vis[st]=1;
	dot[1]=max(dot[1],a[st].y);
	dot[2]=min(dot[2],a[st].y);
	dot[4]=max(dot[4],a[st].x);
	dot[3]=min(dot[3],a[st].x);
	for(int j=head[st];j;j=nxt[j])
		if(!vis[son[j]]) dfs(son[j]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			dot[1]=a[i].y;
			dot[2]=a[i].y;
			dot[3]=a[i].x;
			dot[4]=a[i].x;
			dfs(i);
			ans=min(ans,C(dot[1]-dot[2],dot[4]-dot[3]));
		}
	}
	printf("%d",ans);
	return 0;
}
