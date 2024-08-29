#include<bits/stdc++.h>
#define ll long long
#define M 60 
using namespace std;
inline ll read()
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
ll n,m,c[M];
inline bool check(ll x)
{
	ll cnt=0;
	for(int i=1;i<=n;++i)cnt+=max(x-c[i],0ll);
	return cnt<=x;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i)c[i]=read();
	c[++n]=m;
	ll ans,l=1,r=1e10;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	write(ans);
    return 0;
}

