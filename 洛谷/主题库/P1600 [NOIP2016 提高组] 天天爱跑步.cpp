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
struct node
{
	int nxt,to;
}edge[3][1200010];
int tot,buk[3][600010],top[600010],dis[600010],s[600010],t[600010],lg[600010],dep[600010],ans[600010],val[600010],hd[3][600010],f[600010][25];
inline void addedge(int id,int u,int v)
{
	edge[id][++tot].to=v;
	edge[id][tot].nxt=hd[id][u];
	hd[id][u]=tot; 
}
inline void dfs1(int pos,int fa)
{
	f[pos][0]=fa;
	dep[pos]=dep[fa]+1;
	for(int i=1;i<=lg[dep[pos]];++i)f[pos][i]=f[f[pos][i-1]][i-1];
	for(int i=hd[0][pos];i;i=edge[0][i].nxt)
	{
		if(edge[0][i].to==fa)continue;
		dfs1(edge[0][i].to,pos);
	}
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]>dep[y])x=f[x][lg[dep[x]-dep[y]]];
	if(x==y)return x;
	for(int i=lg[dep[x]];~i;--i)if(f[x][i]^f[y][i])x=f[x][i],y=f[y][i];		
	return f[x][0];
}
inline void dfs2(int pos)
{
	int t1=buk[1][val[pos]+dep[pos]],t2=buk[2][val[pos]-dep[pos]+300000];
	for(int i=hd[0][pos];i;i=edge[0][i].nxt)
	{
		int to=edge[0][i].to;
		if(to==f[pos][0])continue;
		dfs2(to);
	}
	buk[1][dep[pos]]+=top[pos];
	for(int i=hd[1][pos];i;i=edge[1][i].nxt)
	{
		int to=edge[1][i].to;
		++buk[2][dis[to]-dep[t[to]]+300000];
	}
	ans[pos]+=buk[1][val[pos]+dep[pos]]+buk[2][val[pos]-dep[pos]+300000]-t1-t2;
	for(int i=hd[2][pos];i;i=edge[2][i].nxt)
	{
		int to=edge[2][i].to;
		--buk[1][dep[s[to]]];
		--buk[2][dis[to]-dep[t[to]]+300000];
	}
}
int main()
{
	//freopen("running1.in","r",stdin);
	//freopen("running.out","w",stdout);
	int n=read(),m=read();
	lg[0]=-1;
	for(int i=1;i<=n;++i)lg[i]=lg[i>>1]+1;
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		addedge(0,u,v);
		addedge(0,v,u);
	}
	dfs1(1,0);
	for(int i=1;i<=n;++i)val[i]=read();
	for(int i=1;i<=m;++i)
	{
		s[i]=read(),t[i]=read();
		int lca=LCA(s[i],t[i]);
		dis[i]=dep[s[i]]+dep[t[i]]-(dep[lca]<<1);
		++top[s[i]];
		addedge(1,t[i],i);
		addedge(2,lca,i);
		if(dep[lca]+val[lca]==dep[s[i]])--ans[lca];
	}
	dfs2(1);
	for(int i=1;i<=n;++i)write(ans[i]),putchar(' ');
    return 0;
}
