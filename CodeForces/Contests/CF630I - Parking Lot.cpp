#include<bits/stdc++.h>
#define ll long long
using namespace std;
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
ll qpow(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		if(y&1)res=res*x;
		x=x*x;
		y>>=1;
	}
	return res;
}
ll C(ll a,ll b)
{
	if(a<0||b-a<0)return 0;
	ll res=1;
	for(ll i=b-a+1;i<=b;++i)
		res=res*i/(i-b+a);
	return res;
}
int main()
{
	ll n=read(),ans=0;
	for(int i=1;i<=2*n-2-n+1;++i)
	{
		ll res=1;
		for(int j=1;j<i;++j)res*=(4-(j==i-1));
		for(int j=i+n;j<=2*n-2;++j)res*=(4-(j==i+n));
		ans+=(res*4);
	}
	write(ans);
	return 0;
}

