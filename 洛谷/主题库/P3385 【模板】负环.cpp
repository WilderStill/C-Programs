#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define M 114514
using namespace std;
struct edge
{
	int v,w,nxt;
}edge[4*M];
int hd[M],vis[M],cnt[M],tot,n,m,t;
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
	scanf("%d",&t);
	while(t--)
	{
		bool fg=0;
		scanf("%d%d",&n,&m);
		memset(hd,0,sizeof(hd));
		for(int i=1,op,x,y,z;i<=m;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);
			if(z>=0)add(y,x,z);
		}
		memset(dis,INF,sizeof(dis));
		memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));
		while(!q.empty())q.pop();
		dis[1]=0;vis[1]=1;q.push(1);
		while(!q.empty())//SPFA
		{  
			int top=q.front();
			q.pop();
			vis[top]=0;
			for(int i=hd[top];i;i=edge[i].nxt)
				if(dis[top]+edge[i].w<dis[edge[i].v])
				{
					dis[edge[i].v]=dis[top]+edge[i].w;
					cnt[edge[i].v]=cnt[top]+1;
					if(cnt[edge[i].v]>=n){fg=1;break;}
					if(!vis[edge[i].v])
					{
						vis[edge[i].v]=1;q.push(edge[i].v);
					}
				}
			if(fg)break;
		}
		if(fg)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
