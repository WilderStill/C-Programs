#include<bits/stdc++.h>
#define ll __int128
using namespace std;
ll k,c[100010],m[100010];
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
void exgcd(ll a,ll b,ll &x,ll& y)
{
    if(!b)
	{
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=x*(a/b);
}
ll getinv(ll a,ll mod)
{
    ll x,y;
	exgcd(a,mod,x,y);
    return (x+mod)%mod?(x+mod)%mod:mod;
}
int main()
{
    k=read();
	bool fg=0;
    for(int i=1;i<=k;++i)m[i]=read(),c[i]=read();
    for(int i=2;i<=k;++i)
    {
        ll t=__gcd(m[i-1],m[i]),mi=m[i];
        if((c[i]-c[i-1])%t){fg=1;puts("-1");break;}
        m[i]=m[i-1]*m[i]/t;
        c[i]=getinv(m[i-1]/t,mi/t)*((c[i]-c[i-1])/t)%(mi/t)*m[i-1]+c[i-1];
        c[i]=(c[i]%m[i]+m[i])%m[i];
    }
    if(!fg)write(c[k]);
    return 0;
}
