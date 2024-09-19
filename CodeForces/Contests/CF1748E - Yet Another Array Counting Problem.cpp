#include<bits/stdc++.h>
using namespace std;
typedef long long lkz; 
#define M 1000100
const int mod=1000000007;
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
inline void write(lkz x)
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
int m,n,p[M],lson[M],rson[M],stk[M];
vector<vector<lkz>>f;
inline void dfs(int rt)
{
	for(int i=1;i<=m;++i)f[rt][i]=1;
    if(lson[rt])
	{
		dfs(lson[rt]);
		for(int i=1;i<=m;++i)(f[rt][i]*=f[lson[rt]][i-1])%=mod;
	}
    if(rson[rt])
	{
		dfs(rson[rt]);
		for(int i=1;i<=m;++i)(f[rt][i]*=f[rson[rt]][i])%=mod;
	}
    for(int i=1;i<=m;++i)(f[rt][i]+=f[rt][i-1])%=mod;
}
int main()
{
	int T=read();
	while(T--)
	{
		memset(stk,0,sizeof stk);
		memset(lson,0,sizeof lson);
		memset(rson,0,sizeof rson);
		n=read(),m=read();
		int top=0;
		f.resize(n+1);
        for(int i=1;i<=n;++i)f[i].resize(m+1);
		for(int i=1;i<=n;++i)p[i]=read();
		for(int i=1;i<=n;++i)
		{
			int k=top;
			while(k&&p[stk[k]]<p[i])--k;
			if(k)rson[stk[k]]=i; 
			if(k<top)lson[i]=stk[k+1];
			stk[++k]=i;
			top=k;
		}
        dfs(stk[1]);
        write(f[stk[1]][m]),puts("");
	}
    return 0;
}

