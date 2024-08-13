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
	int from,to;
}edge[114514];
int fa[114514],ind[114514],mp[114514],d[114154],syh[114514],cnt1,coi;
bitset<114514>dg[505];
int findfa(int x){return (fa[x]^x)?fa[x]=findfa(fa[x]):x;}
int main()
{
	int n=read(),m=read(),rt=1;
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i)
	{
		edge[i].from=read();
		edge[i].to=read();
		++ind[edge[i].from];
		++ind[edge[i].to];
	}
	for(int i=2;i<=n;++i)if(ind[i]<ind[rt])rt=i;
	for(int i=1;i<=m;++i)
	{
		if(edge[i].from==rt)mp[edge[i].to]=1;
		if(edge[i].to==rt)mp[edge[i].from]=1;
	}
	for(int i=1;i<=n;++i)
	{
		if(mp[i]==1)d[++cnt1]=i,syh[i]=cnt1;
		else fa[i]=rt;
	}
	for(int i=1;i<=m;++i)
	{
        if(mp[edge[i].from]==1)dg[syh[edge[i].from]][edge[i].to]=1;
        if(mp[edge[i].to]==1)dg[syh[edge[i].to]][edge[i].from]=1;
    }
    for(int i=1;i<=cnt1;++i)
	{
        int x=d[i];
        for(int y=1;y<=n;++y)
		{
            if(dg[i][y])continue;
            int xfa=findfa(x),yfa=findfa(y);
            if(xfa==yfa)continue;
            ++coi,fa[xfa]=yfa;
        }
    }
	write(cnt1-coi);
	return 0;
}

