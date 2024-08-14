#include<bits/stdc++.h>
#define ll long long
#define M 101
using namespace std;
ll n,m,q,num[M];
static ll sta[36];
inline ll read()
{
    ll x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}
inline void write(ll x)
{
    ll top=0;
    do{
    	sta[top++]=x%10,x/=10;
    }while(x);
    while(top)putchar(sta[--top]+48);
}
struct Matrix
{
	bitset<M>bits[M];
	Matrix(){for(register ll i=1;i<=n;++i)bits[i].reset();}
	Matrix operator *(const Matrix &b)const
	{
		register Matrix res;
		for(register ll i=1;i<=n;++i)
			for(register ll j=1;j<=n;++j)
				if(bits[i][j])
					res.bits[i]^=b.bits[j];
		return res;
	}
}ans,f;
inline Matrix qpow(Matrix x,ll y)
{
	register Matrix res;
	for(register ll i=1;i<=n;++i)res.bits[i][i]=1;
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
	n=read(),m=read(),q=read();
	for(register ll i=1;i<=n;++i)num[i]=read();
	for(register ll i=1,x,y;i<=m;++i)
	{
		x=read(),y=read();
		f.bits[x][y]=f.bits[y][x]=1;
	}
	for(register ll i=1,t;i<=q;++i)
	{
		t=read();
		ans=qpow(f,t);
		register ll res=0;
		for(register ll i=1;i<=n;++i)
			if(ans.bits[1][i])
				res^=num[i];
		write(res);
		putchar('\n');
	}
	return 0;
}
