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
	int nxt,to,val;
}edge[600010];
int tot,res,lg[300010],dep[300010],hd[300010],f[300010][25],dis[300010],num[300010][25],dg[300010];
inline void addedge(int u,int v,int w)
{
	edge[++tot].to=v;
	edge[tot].nxt=hd[u];
	edge[tot].val=w;
	hd[u]=tot; 
}
inline void dfs(int pos)
{
	int sum=0;
	for(int i=1;i<25;++i)f[pos][i]=f[f[pos][i-1]][i-1],num[pos][i]=num[pos][i-1]+num[f[pos][i-1]][i-1];
	for(int i=hd[pos];i;i=edge[i].nxt)
	{
		int to=edge[i].to;
		if(to==f[pos][0])continue;
		f[to][0]=pos;
		num[to][0]=edge[i].val;
		dep[to]=dep[pos]+1;
		dis[to]=dis[pos]+edge[i].val;
		dfs(to);
		sum+=dg[to];
	}
	if(sum+dg[pos]<0)dg[pos]=-1;
	else dg[pos]=0;
}
inline void dfs_syh(int pos)
{
	for(int i=hd[pos];i;i=edge[i].nxt)
	{
		int to=edge[i].to;
		if(to==f[pos][0])continue;
		if(!dg[to]&&dg[pos]==-1)dg[to]=pos;
		if(!dg[to]&&dg[pos]!=-1)dg[to]=dg[pos];
		if(dg[to]==-1)res+=edge[i].val;
		dfs_syh(to);
	}
	if(dg[pos]>0)dis[pos]-=dis[dg[pos]];
}
inline int LCA(int x,int y)
{
	if(x==y)return 0;
	if(dep[x]<dep[y])swap(x,y);
	int syh=0;
	for(int i=24;~i;--i)
		if(dep[f[x][i]]>dep[y])
			syh+=num[x][i],x=f[x][i];
	if(dep[x]^dep[y])syh+=num[x][0],x=f[x][0];
	if(x==y)return syh;
	for(int i=24;~i;--i)
		if(f[x][i]^f[y][i])
			syh+=num[x][i]+num[y][i],x=f[x][i],y=f[y][i];
	syh+=num[x][0]+num[y][0];	
	return syh;
}
int main()
{
	int n=read(),q=read(),k=read(),root;
	lg[0]=-1;
	for(int i=1;i<=n;++i)lg[i]=lg[i>>1]+1;
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read(),w=read();
		addedge(u,v,w),addedge(v,u,w);
	}
	for(int i=1;i<=k;++i)dg[root=read()]=-1;
	dfs(root);
	dfs_syh(root);
	for(int i=1;i<=q;++i)
	{
		int s=read(),t=read(),ans=res<<1;
		if(~dg[s])ans+=dis[s],s=dg[s];
		if(~dg[t])ans+=dis[t],t=dg[t];
		ans-=LCA(s,t);
		write(ans);
		puts("");
	}
    return 0;
}
