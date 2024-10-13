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
	freopen("hope.in","r",stdin);
	freopen("hope.out","w",stdout);
}
const int M=100010;
struct node
{
    int from,to,nxt;
}edge[M<<1];
int tot,hd[M],size[M],dep[M],maxdep;
inline void addedge(int u,int v)
{
	edge[++tot].from=u;
	edge[tot].to=v;
	edge[tot].nxt=hd[u];
	hd[u]=tot;
}
inline void dfs(int pos,int fa)
{
	dep[pos]=dep[fa]+1;
	maxdep=max(maxdep,dep[pos]);
	size[pos]=1;
	for(int i=hd[pos];i;i=edge[i].nxt)
	{
		int to=edge[i].to;
		if(to==fa)continue;
		dfs(to,pos);
		size[pos]+=size[to];
	}
}
int main()
{
	//file();
	int n=read();
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		addedge(u,v),addedge(v,u);
	}
	dfs(1,0);
//	cout<<maxdep<<" syh\n";
//	for(int i=1;i<=n;++i)
//		write(size[i]),puts("");
	for(int i=1;i<=n;++i)
		write(i<=maxdep?i-1:i*2-1-maxdep),puts("");
    return cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n',0;
}
/*
5
1 2
1 3
2 4
2 5
*/
