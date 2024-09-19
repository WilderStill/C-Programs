#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define M 300010
#define ll long long
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	return x*f;
}
inline void write(ll x)
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
int Fa[M],query[M][3],dep[M],rt[M];
ll syh,fa[M][25],num[M][25];
int findfa(int x){return Fa[x]==x?x:Fa[x]=findfa(Fa[x]);}
void dfs(int pos,int prefa,int val,int pt)
{
    rt[pos]=pt;
    fa[pos][0]=prefa,num[pos][0]=val;
    dep[pos]=dep[prefa]+1;
    for(int i=1;i<=24;++i)fa[pos][i]=fa[fa[pos][i-1]][i-1],num[pos][i]=max(num[pos][i-1],num[fa[pos][i-1]][i-1]);
	for(auto nd:graph[pos])
	{
		int v=nd.to,val=nd.val;
		if(v==prefa)continue;
		dfs(v,pos,val,pt);
	}
}
inline ll LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	ll res=-INF;
	for(int i=24;~i;--i)
	{
        if(dep[fa[x][i]]>=dep[y])
		{
            res=max(res,num[x][i]);
			x=fa[x][i];
        }
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
    int n=read(),m=read();
    for(int i=1;i<=n;++i)Fa[i]=i;
    for(int i=1;i<=m;++i)query[i][0]=edge[i].from=read(),query[i][1]=edge[i].to=read(),query[i][2]=edge[i].val=read();
    sort(edge+1,edge+m+1,cmp);
    for(int i=1;i<=m;++i)
	{
        int xfa=findfa(edge[i].from),yfa=findfa(edge[i].to);
        if(xfa==yfa)continue;
        Fa[xfa]=yfa;
        graph[edge[i].from].push_back({0,edge[i].to,edge[i].val});
        graph[edge[i].to].push_back({0,edge[i].from,edge[i].val});
        syh+=edge[i].val;
    }
    for(int i=1;i<=n;++i)if(!rt[i])dfs(i,0,0,i);
    for(int i=1;i<=m;++i)
	{
        write(syh+query[i][2]-LCA(query[i][0],query[i][1]));
        puts("");
    }
    return 0;
}
