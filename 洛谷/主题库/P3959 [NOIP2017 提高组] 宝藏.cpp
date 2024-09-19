#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int ans=INF,n,m,tot,ed,vis[14],dep[14],cost[14][14];
vector<int>mp[14];
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))
	{
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch))
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline void write(int x)
{
    if(x<0)
	{
        putchar('-');
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
int cmp_i;
inline bool cmp(int x,int y)
{
	return cost[cmp_i][x]<cost[cmp_i][y];
}
inline void dfs(int pos,int id,int sum)
{
	for(int i=pos;i<=ed;++i)
	{
		if(sum+tot*dep[vis[i]]>=ans)return;
		for(int j=id;j<mp[vis[i]].size();++j)
		{
			if(!dep[mp[vis[i]][j]])
			{
				vis[++ed]=mp[vis[i]][j];
				tot-=cost[vis[ed]][mp[vis[ed]][0]];
				dep[vis[ed]]=dep[vis[i]]+1;
				dfs(i,j+1,sum+cost[vis[i]][vis[ed]]*dep[vis[i]]);
				dep[vis[ed]]=0;
				tot+=cost[vis[ed]][mp[vis[ed]][0]];
				--ed;
			}
		}
		id=0;
	}
    if(ed==n)
	{
        ans=min(sum,ans);
        return;
    }
}
int main()
{
    n=read(),m=read();
    memset(cost,INF,sizeof cost);
    if(n==1)
    {
    	write(0);
    	return 0;
	}
    for(int i=1,u,v,w;i<=m;++i)
    {
    	u=read(),v=read(),w=read();
		if(cost[u][v]<w)continue;
    	if(cost[u][v]==INF)mp[u].push_back(v),mp[v].push_back(u);
        cost[u][v]=cost[v][u]=w;
	}
	for(int i=1;i<=n;++i)
	{
		cmp_i=i;
		sort(mp[i].begin(),mp[i].end(),cmp);
		tot+=cost[i][mp[i][0]];
	}
	for(int i=1;i<=n;++i)
	{
        vis[ed=1]=i;
        tot-=cost[i][mp[i][0]];
        dep[i]=1;
        dfs(1,0,0);
        dep[i]=0;
        tot+=cost[i][mp[i][0]];
    }
    write(ans);
    return 0;
}
