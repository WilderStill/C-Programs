#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define M 114514
using namespace std;
struct edge
{
	int v,w,nxt;
}edge[4*M];
int hd[M],vis[M],cnt[M],tot,n,m;
ll ans,dis[M];
queue<int> q;
void add(int u,int v,int w)
{
	edge[++tot].v=v;
	edge[tot].w=w;
	edge[tot].nxt=hd[u];
	hd[u]=tot;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,op,x,y,z;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add(y,x,z);
	}
	for(int i=1;i<=n;i++)add(0,i,0);
	memset(dis,INF,sizeof(dis));
	dis[0]=0;vis[0]=1;q.push(0);
	while(!q.empty())//SPFA
	{  
		int top=q.front();
		q.pop();
		vis[top]=0;
		for(int i=hd[top];i;i=edge[i].nxt)
			if(dis[top]+edge[i].w<dis[edge[i].v])
			{
				dis[edge[i].v]=dis[top]+edge[i].w;
				if (!vis[edge[i].v])
				{
					vis[edge[i].v]=1;
					cnt[edge[i].v]++;
					if(cnt[edge[i].v]>=n+1){printf("NO\n");return 0;}
					q.push(edge[i].v);
				}
			}
	}
	for(int i=1;i<=n;i++)printf("%lld ",dis[i]);
	return 0;
}
