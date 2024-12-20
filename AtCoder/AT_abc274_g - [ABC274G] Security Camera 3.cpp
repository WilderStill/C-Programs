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
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
int cnt1,cnt2,tot,id=1,match[1000010],dfn[1000010],hd[1000010],ln[5010][5010],rw[5010][5010];
char ch[5010][5010];
struct node
{
	int to,nxt;
}edge[1000010];
inline void addedge(int u,int v)
{
	edge[++tot].nxt=hd[u];
	edge[tot].to=v;
	hd[u]=tot;
}
inline bool found(int x)
{
	for(int i=hd[x];i;i=edge[i].nxt)
	{
		int to=edge[i].to;
		if(dfn[to]-id)
		{
			dfn[to]=id;
			if(!match[to]||found(match[to]))
			{
				match[to]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int n=read(),m=read(),ans=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",ch[i]+1);
		for(int j=1;j<=m;++j)
			if(ch[i][j]=='.')
			{
				if(j==1||ch[i][j-1]!='.')ln[i][j]=++cnt1;
				else ln[i][j]=cnt1;
			}	
	}
	for(int j=1;j<=m;++j)
		for(int i=1;i<=n;++i)
			if(ch[i][j]=='.')
			{
				if(i==1||ch[i-1][j]!='.')rw[i][j]=++cnt2;
				else rw[i][j]=cnt2;
				addedge(ln[i][j],rw[i][j]);
			}
	for(int i=1;i<=cnt1;++i,++id)ans+=found(i);
	write(ans);
	return 0;
}
