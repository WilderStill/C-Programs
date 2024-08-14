#include<bits/stdc++.h>
#define ll __int128
using namespace std;
ll n,a[114514],b[114514],Mi[114514],sum=1,ans;
inline ll read()
{
	register ll x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x;
}
inline void print(ll x)
{
	if(x>=10) print(x/10);
	putchar(x%10+'0');
}
ll exgcd(ll a,ll b,ll&x,ll&y)
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	ll d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
int main()
{
    n=read();
    for(ll i=1;i<=n;++i)
	{
        a[i]=read();
        sum*=a[i];
        b[i]=read();
    }
    for(ll i=1,x,y;i<=n;++i)
	{
        exgcd(sum/a[i],a[i],x,y);
        ans+=b[i]*(sum/a[i])*(x<0?x+a[i]:x);
    }
    print(ans%sum);
    return 0;
}
