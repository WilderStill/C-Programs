#include<bits/stdc++.h>
using namespace std;
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
inline void file()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
}
struct node
{
    int from,to,nxt,val;
}edge[20010];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
int hd[20010],dis[20010][110],tot;
bool vis[20010][110];
inline void addedge(int u,int v,int w)
{
	edge[++tot].from=u;
	edge[tot].to=v;
	edge[tot].val=w;
	edge[tot].nxt=hd[u];
	hd[u]=tot;
}
int main()
{
	//file();
	int n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
	}
	memset(dis,0x3f,sizeof dis);
	dis[1][0]=0;
	q.push({0,1});
	while(!q.empty())
	{
		int pos=q.top().second,val=q.top().first;
		q.pop();
		if(vis[pos][val%k])continue;
		vis[pos][val%k]=1;
		for(int i=hd[pos];i;i=edge[i].nxt)
		{
			int to=edge[i].to,tval=edge[i].val,tp=(val+1)%k;
			if(val>=tval)tp=val;
			else tp=((tval-val+k-1)/k)*k+val;
			if(dis[to][(tp+1)%k]>tp+1)
			{
				dis[to][(tp+1)%k]=tp+1;
				q.push({tp+1,to});
			}
		}
	}
	if(dis[n][0]==0x3f3f3f3f)puts("-1");
    else write(dis[n][0]);
    return cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n',0;
}
