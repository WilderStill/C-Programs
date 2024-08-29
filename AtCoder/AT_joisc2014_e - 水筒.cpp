#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define M 5000010
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
int cnt,Fa[M],fa[M][25],num[M][25],dep[M],rt[M];
int findfa(int x){return Fa[x]==x?x:Fa[x]=findfa(Fa[x]);}
void dfs(int pos,int prefa,int val,int pt)
{
    rt[pos]=pt;
    fa[pos][0]=prefa,num[pos][0]=val;
    dep[pos]=dep[prefa]+1;
    for(int i=1;i<=log2(dep[pos]);++i)fa[pos][i]=fa[fa[pos][i-1]][i-1],num[pos][i]=max(num[pos][i-1],num[fa[pos][i-1]][i-1]);
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
	int maxn=log2(dep[x]);
	for(int i=maxn;~i;--i)
		if(fa[x][i]^fa[y][i])
		{
			res=max({res,num[x][i],num[y][i]});
			x=fa[x][i],y=fa[y][i];
		}	
	res=max({res,num[x][0],num[y][0]});
	return res;
}
queue<pair<int,int>>q;
const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int n,m,syh[5010][5010],dis[5010][5010];
char mp[5010][5010];
void bfs()
{
	while(!q.empty())
	{
		auto top=q.front(); 
		q.pop();
		int x=top.first,y=top.second;
		for(int i=0;i<4;++i)
		{
			int xx=x+dx[i],yy=y+dy[i];
			if(xx>0&&xx<=n&&yy>0&&yy<=m&&mp[xx][yy]!='#')
			{
				if(!syh[xx][yy])
				{
					syh[xx][yy]=syh[x][y];
					dis[xx][yy]=dis[x][y]+1;
					q.push({xx,yy});
					continue;
				}
				if(syh[xx][yy]^syh[x][y]) 
				{
					edge[++cnt].from=syh[xx][yy];
					edge[cnt].to=syh[x][y];
					edge[cnt].val=dis[xx][yy]+dis[x][y];
				}
			}
		}
	}
}
int main()
{
    n=read(),m=read();
	int p=read(),qt=read();
    for(int i=1;i<=n;++i)scanf("%s",mp[i]+1);
	for(int i=1;i<=p;++i)
	{
		int u=read(),v=read();
		syh[u][v]=i;
		q.push({u,v});
	}
	bfs();
    for(int i=1;i<=p;++i)Fa[i]=i;
    sort(edge+1,edge+cnt+1,cmp);
    for(int i=1;i<=cnt;++i)
	{
        int xfa=findfa(edge[i].from),yfa=findfa(edge[i].to);
        if(xfa==yfa)continue;
        Fa[xfa]=yfa;
        graph[edge[i].from].push_back({0,edge[i].to,edge[i].val});
        graph[edge[i].to].push_back({0,edge[i].from,edge[i].val});
    }
    for(int i=1;i<=p;++i)if(!rt[i])dfs(i,0,0,i);
    while(qt--)
	{
    	int u=read(),v=read();
        write(rt[u]==rt[v]?LCA(u,v):-1);
        puts("");
    }
    return 0;
}
