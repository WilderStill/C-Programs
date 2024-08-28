#include<bits/stdc++.h>
#define M 400010
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch&15),ch=getchar();
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
struct node
{
	int from,to,nxt;
}edge[M];
int fa[M],hd[M],tg[M],ans[M],tot;
bool can[M];
void addedge(int u,int v)
{
	edge[++tot].from=u;
	edge[tot].to=v;
	edge[tot].nxt=hd[u];
	hd[u]=tot;
}
int findfa(int x){return x==fa[x]?x:fa[x]=findfa(fa[x]);}
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i)
	{
		int u=read()+1,v=read()+1;
		addedge(u,v),addedge(v,u);
	}
	int k=read();
	for(int i=1;i<=k;++i)
	{
		tg[i]=read()+1;
		can[tg[i]]=1;
	}
	int rtot=n-k;
	for(int i=1;i<=tot;++i)
	{
		int from=edge[i].from,to=edge[i].to,ffa=findfa(from),tfa=findfa(to);
		if(!can[from]&&!can[to]&&(ffa^tfa))
		{
			--rtot;
			fa[ffa]=tfa;
		}
	}
	ans[k+1]=rtot;
	for(int t=k;t;--t)
	{
		++rtot;
		can[tg[t]]=0;
		for(int i=hd[tg[t]];i;i=edge[i].nxt)
		{
			int from=tg[t],to=edge[i].to,ffa=findfa(from),tfa=findfa(to);
			if(!can[from]&&!can[to]&&(ffa^tfa))
			{
				--rtot;
				fa[ffa]=tfa;
			}
		}
		ans[t]=rtot;
	}
	for(int i=1;i<=k+1;++i)write(ans[i]),puts("");
    return 0;
}
