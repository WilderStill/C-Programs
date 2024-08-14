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
ll f[1000010],ans;
int main()
{
	ll l=read(),r=read();
	for(ll i=r;i>1;--i)
	{
		f[i]=r/i-(l-1)/i;f[i]*=f[i];
		for(ll j=2;j<=(r/i);++j)f[i]-=f[i*j];
		ans+=f[i];
	}
	for(ll i=max(l,2ll);i<=r;++i)ans-=(r/i*2-1);
	write(ans);
	return 0;
}
