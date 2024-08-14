#include<bits/stdc++.h>
#define ll long long
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
ll mod;
ll qpow(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res%mod;
}
ll n,m,a,b,k,ansm;
ll C(ll a,ll b)
{
	if(a<b)return 0;
	if(b>a-b)b=a-b;
	ll x=1,y=1;
	for(int i=0;i<b;++i)
	{
		x=(x*(a-i))%mod;
		y=(y*(i+1))%mod;
	}
	return x*qpow(y,mod-2)%mod;
}
ll Lucas(ll a,ll b)
{
	if(!b)return 1;
	return Lucas(a/mod,b/mod)*C(a%mod,b%mod)%mod;
}
int main()
{
	int T=read();
	while(T--)
	{
		n=read(),m=read(),mod=read();
		write(Lucas(n+m,n)%mod);
		puts("");
	}
	return 0;
}

