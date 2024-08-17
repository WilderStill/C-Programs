#include<bits/stdc++.h>
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
inline ll readl()
{
	ll x=0,f=1;
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
const ll p=998244353;
inline ll qpow(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		if(y&1)(res*=x)%=p;
		(x*=x)%=p;
		y>>=1;
	}
	return res;
}
int n,m,K;
ll ans,v[110],C[40][40],f[110][40][40][40];
inline void init(int n)
{
	for(int i=0;i<=n;++i)C[i][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i;++j)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%p;
}
int main()
{
	n=read(),m=read(),K=read();
	init(n);
	for(int i=0;i<=m;++i)v[i]=readl();
	f[0][0][0][0]=1;
	for(int i=0;i<=m;++i)
		for(int j=0;j<=n;++j)
			for(int k=0;k<=K;++k)
				for(int l=0;l<=n>>1;++l)
					for(int r=0;r<=n-j;++r)
						f[i+1][j+r][k+(r+l&1)][r+l>>1]=(f[i+1][j+r][k+(r+l&1)][r+l>>1]+f[i][j][k][l]*qpow(v[i],r)%p*C[n-j][r]%p)%p;
	for(int k=0;k<=K;++k)
		for(int t=0;t<=n>>1;++t)
			if(k+__builtin_popcount(t)<=K)ans=(ans+f[m+1][n][k][t])%p;
	write(ans);
	return 0;
}
