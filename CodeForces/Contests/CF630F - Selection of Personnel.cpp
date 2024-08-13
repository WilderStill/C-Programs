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
	ll n=read();
	write(C(5,n)+C(6,n)+C(7,n));
	return 0;
}

