#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define M 500010
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
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
    int from,to;
}edge[M];
vector<node>graph[M];
int Fa[M],fa[M][25],dep[M],rt[M];
int findfa(int x){return Fa[x]==x?x:Fa[x]=findfa(Fa[x]);}
void dfs(int pos,int prefa,int pt)
{
    rt[pos]=pt;
    fa[pos][0]=prefa;
    dep[pos]=dep[prefa]+1;
    for(int i=1;i<=log2(dep[pos]);++i)fa[pos][i]=fa[fa[pos][i-1]][i-1];
	for(auto nd:graph[pos])
	{
		int v=nd.to;
		if(v==prefa)continue;
		dfs(v,pos,pt);
	}
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	int res=INF;
	while(dep[x]>dep[y])
	{
		int lg=log2(dep[x]-dep[y]);
        x=fa[x][lg];
    }
	if(x==y)return x;
	int maxn=log2(dep[x]);
	for(int i=maxn;~i;--i)
		if(fa[x][i]^fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int main()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)Fa[i]=i;
    for(int i=1;i<n;++i)edge[i].from=read(),edge[i].to=read();
    for(int i=1;i<n;++i)
	{
        int xfa=findfa(edge[i].from),yfa=findfa(edge[i].to);
        if(xfa==yfa)continue;
        Fa[xfa]=yfa;
        graph[edge[i].from].push_back({0,edge[i].to});
        graph[edge[i].to].push_back({0,edge[i].from});
    }
    for(int i=1;i<=n;++i)if(!rt[i])dfs(i,0,i);
    for(int i=1;i<=m;++i)
	{
    	int u=read(),v=read(),w=read();
        int a=LCA(u,v),b=LCA(u,w),c=LCA(v,w);
        if(a==b)write(c),putchar(' ');
		else if(a==c)write(b),putchar(' ');
		else if(b==c)write(a),putchar(' ');
        write(dep[u]+dep[v]+dep[w]-dep[a]-dep[b]-dep[c]);
        puts("");
    }
    return 0;
}
