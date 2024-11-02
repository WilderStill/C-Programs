#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read()
{
    ll x=0,f=1;
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
inline void file()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
}
int n,m,K;
struct node
{
    int u,v;
	ll w;
}edge[3010];
struct Matrix
{
    ll a[110][110];
    void reset(ll x=0x3f){memset(a,x,sizeof a);}
    inline Matrix operator*(const Matrix &b)const
	{
        Matrix res;
		res.reset();
        for(int k=1;k<=n;++k)
            for(int i=1;i<=n;++i)
                for(int j=1;j<=n;++j)
                    res.a[i][j]=min(res.a[i][j],a[i][k]+b.a[k][j]);
        return res;
    }
}tp;
ll mp[110][110];
inline Matrix qpow(Matrix x,int y)
{
	Matrix res;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			res.a[i][j]=mp[i][j];
	while(y)
	{
		if(y&1)res=res*x;
		x=x*x;
		y>>=1;
	}
	return res;
}
int main()
{
	//file();
	n=read(),m=read(),K=read();
	memset(mp,0x3f,sizeof mp);
	for(int i=1;i<=n;++i)mp[i][i]=0;
	tp.reset();
	for(int i=1;i<=m;++i)
	{
		edge[i].u=read(),edge[i].v=read(),edge[i].w=read();
		mp[edge[i].u][edge[i].v]=edge[i].w;
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
	for(int k=1;k<=m;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				tp.a[i][j]=min(tp.a[i][j],min(mp[i][j],mp[i][edge[k].u]+mp[edge[k].v][j]-edge[k].w));
	write(qpow(tp,K).a[1][n]);
    return cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n',0;
}
