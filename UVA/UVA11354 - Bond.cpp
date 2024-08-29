#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define M 100010
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
    int from,to,val;
}edge[M];
bool cmp(node a,node b){return a.val<b.val;}
vector<node>graph[M];
int Fa[M],fa[M][25],num[M][25],dep[M],rt[M];
inline int findfa(int x){return Fa[x]==x?x:Fa[x]=findfa(Fa[x]);}
inline void dfs(int pos,int prefa,int val,int pt)
{
    rt[pos]=pt;
    fa[pos][0]=prefa,num[pos][0]=val;
    dep[pos]=dep[prefa]+1;
    for(int i=1;i<25;++i)fa[pos][i]=fa[fa[pos][i-1]][i-1],num[pos][i]=max(num[pos][i-1],num[fa[pos][i-1]][i-1]);
	for(auto nd:graph[pos])
	{
		int v=nd.to,val=nd.val;
		if(v==prefa)continue;
		dfs(v,pos,val,pt);
	}
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	int res=-INF;
	while(dep[x]>dep[y])
	{
		int lg=log2(dep[x]-dep[y]);
        res=max(res,num[x][lg]);
        x=fa[x][lg];
    }
	if(x==y)return res;
	for(int i=24;~i;--i)
		if(fa[x][i]^fa[y][i])
		{
			res=max({res,num[x][i],num[y][i]});
			x=fa[x][i],y=fa[y][i];
		}	
	res=max({res,num[x][0],num[y][0]});
	return res;
}
int main()
{
    int n,m,t=0;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
    	if(t)puts("");
    	else ++t;
    	memset(fa,0,sizeof fa);
    	memset(dep,0,sizeof dep);
    	memset(rt,0,sizeof rt);
    	memset(num,0,sizeof num);
    	for(int i=1;i<=n;++i)Fa[i]=i;
    	for(int i=0;i<M;++i)graph[i].clear();
	    for(int i=1;i<=m;++i)edge[i].from=read(),edge[i].to=read(),edge[i].val=read();
	    sort(edge+1,edge+m+1,cmp);
	    for(int i=1;i<=m;++i)
		{
	        int xfa=findfa(edge[i].from),yfa=findfa(edge[i].to);
	        if(xfa==yfa)continue;
	        Fa[xfa]=yfa;
	        graph[edge[i].from].push_back({0,edge[i].to,edge[i].val});
	        graph[edge[i].to].push_back({0,edge[i].from,edge[i].val});
	    }
	    for(int i=1;i<=n;++i)if(!rt[i])dfs(i,0,0,i);
	    int q=read();
	    while(q--)
		{
	    	int u=read(),v=read();
	        write(rt[u]==rt[v]?LCA(u,v):-1);
	        puts("");
	    }
	} 
    return 0;
}
