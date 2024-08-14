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
	    scanf("%d",&op);
	    switch(op)
	    {
	    	case 1:{scanf("%d%d%d",&x,&y,&z);add(y,x,z);break;}
	    	case 2:{scanf("%d%d%d",&x,&y,&z);add(x,y,-z);break;}
	    	default:{scanf("%d%d",&x,&y);add(x,y,0),add(y,x,0);break;}
		}
	}
	for(int i=1;i<=n;i++)add(0,i,0);
	memset(dis,-INF,sizeof(dis));
	dis[0]=0;vis[0]=1;q.push(0);
	while(!q.empty())//SPFA
	{  
		int top=q.front();
		q.pop();
		vis[top]=0;
		for(int i=hd[top];i;i=edge[i].nxt)
			if(dis[top]+edge[i].w>dis[edge[i].v])
			{
				dis[edge[i].v]=dis[top]+edge[i].w;
				if (!vis[edge[i].v])
				{
					vis[edge[i].v]=1;
					q.push(edge[i].v);
					cnt[edge[i].v]++;
					if(cnt[edge[i].v]>=n){printf("No\n");return 0;}
				}
			}
	}
	printf("Yes\n");
	return 0;
}
