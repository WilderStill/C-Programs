#include<bits/stdc++.h>
#define ll __int128
using namespace std;
ll n,a[114514],b[114514],Mi[114514],sum=1,ans;
inline ll read()
{
	register ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
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
    for(ll i=1;i<=n;++i)a[i]=read();
    for(ll i=1;i<=n;++i){b[i]=read();sum*=b[i];}
    for(ll i=1;i<=n;++i){a[i]=(a[i]+sum)%sum;}
    for(ll i=1,x,y;i<=n;++i)
	{
        ll tmp=sum/b[i];
		exgcd(tmp,b[i],x,y);
        x=(b[i]+x%b[i])%b[i];
        ans=(ans+a[i]*tmp*x+sum)%sum;
    }
    print((ans+sum)%sum);
    return 0;
}
