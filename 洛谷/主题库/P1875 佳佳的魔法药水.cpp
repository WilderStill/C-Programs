#include<bits/stdc++.h>
#define ll long long
#define N 1145
#define M 1145141
#define INF 0x3f3f3f3f
using namespace std;
int edge[N][N],dis[M],u,v,d,n;
ll ans[M];bool vis[1145];
void dijkstra()
{
    for(int i=1;i<=n;i++)
    {
    	int t=0;
        for(int j=1;j<=n;j++)
		{
			if(!vis[j]&&(t==0||dis[j]<dis[t]))t=j;
		}
		vis[t]=1;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]&&edge[t][j]!=INF)
			{
				if(dis[t]+dis[j]<dis[edge[t][j]])
				{
					dis[edge[t][j]]=dis[j]+dis[t];
					ans[edge[t][j]]=ans[t]*ans[j];
				}
				else if(dis[t]+dis[j]==dis[edge[t][j]])ans[edge[t][j]]+=ans[t]*ans[j];
			}
		}
    }
}
int main()
{
    scanf("%d",&n);
    memset(edge,INF,sizeof(edge));
    for(int i=1;i<=n;i++)scanf("%d",&dis[i]),ans[i]=1;
    while(scanf("%d%d%d",&u,&v,&d)!=EOF)
        edge[u+1][v+1]=edge[v+1][u+1]=d+1;
    dijkstra();
    printf("%d %lld",dis[1],ans[1]);
    return 0;
}
