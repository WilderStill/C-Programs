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
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
int tot,dis[500010],hd[500010],vis[500010];
struct node
{
	int nxt,to,val;
}edge[1000010];
void addedge(int u,int v,int w)
{
	edge[++tot].nxt=hd[u];
	edge[tot].to=v;
	edge[tot].val=w;
	hd[u]=tot;
}
queue<int>q;
int main()
{
	int T=read();
    while(T--)
	{
		memset(dis,-0x3f,sizeof dis);
        memset(vis,0,sizeof vis);
        memset(hd,0,sizeof hd);
        int n=read(),maxn=-1145;tot=0;
        for(int i=1;i<=n;++i)
		{
        	int u=read(),v=read(),w=read();
        	addedge(u,v+1,w);
            maxn=max(maxn,v);
        }
        for(int i=0;i<=maxn;++i)
		{
			addedge(i+1,i,-1);
			addedge(i,i+1,0);
	    }
	    dis[0]=0;
	    vis[0]=1;
	    q.push(0);
	    while(!q.empty())
		{
	        int tp=q.front();
	        q.pop();
	        vis[tp]=0;
	        for(int i=hd[tp];i;i=edge[i].nxt)
			{
	            int to=edge[i].to,val=edge[i].val;
	            if(dis[to]<dis[tp]+val)
				{
	                dis[to]=dis[tp]+val;
	                if(!vis[to])q.push(to),vis[to]=1;
	            }
	        }
	    }
	    write(dis[maxn+1]);
	    puts("");
    }
	return 0;
}
