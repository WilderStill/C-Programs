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
int n,m,mp[1010][1010],fa[1010],del,pos;
int findfa(int x)
{
	return x==fa[x]?x:fa[x]=findfa(fa[x]);
}
void merge(int x,int y)
{
	x=findfa(x),y=findfa(y);
	if(x!=y)fa[x]=y;
}
int main()
{
	n=read(),m=read();
	memset(mp,20,sizeof(mp));
	for(int i=1;i<=n;++i)mp[i][i]=0;
	for(int i=1;i<=2*n;++i)fa[i]=i;
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read(),op=read();
		merge(u+n,v),merge(v+n,u);
		if(op==1)
		{
			mp[u][v]=1;
			mp[v][u]=-1;
		}
		else
		{
			mp[u][v]=1;
			mp[v][u]=1;
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(findfa(i)==findfa(i+n))
		{
			puts("NO");
			return 0;
		}
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				mp[i][j]=min(mp[i][k]+mp[k][j],mp[i][j]);
	int cnt=0;
	for(int i=1;i<=n;++i)
	{
		int maxn=-n-1;
		if(mp[i][i]<0)
		{
			puts("NO");return 0;
		}
		for(int j=1;j<=n;++j)
		{
			maxn=max(mp[i][j],maxn);
		}
		if(maxn>=del)del=maxn,pos=i;
	}
	puts("YES"),write(del),puts("");
	for(int i=1;i<=n;++i)
		write(mp[pos][i]),putchar(' ');
	return 0;
}

