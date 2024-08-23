#include<bits/stdc++.h>
#define maxpow 60
#define ll __int128
using namespace std;
const ll mod=1e18+1;
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
inline ll qpow(ll x,int y)
{
	ll res=1;
	while(y)
	{
		if(x>=mod)return mod;
		if(y&1)res*=x;
		x*=x;
		y>>=1;
	}
	return res>=mod?mod:res;
}
inline ll qroot(ll n,int k)
{
	ll l=1,r=n,ans;
	while(l<=r) 
	{
		ll mid=l+r>>1;
		if(qpow(mid,k)<=n)l=mid+1,ans=mid;
		else r=mid-1;
	}
	return ans;
}
int main()
{
	ll n=read(),ans=1;
	int K=read();
	if(K==1)
	{
		write(n);
		return 0;
	}
	if(K==2)ans+=qroot(n,2)-1;
	for(int i=max(K,3);i<=maxpow;++i)
	{
		ll uplim=qroot(n,i);
		for(ll j=2;j<=uplim;++j)
		{
			ll tp=qpow(j,i),fg=1;
			for(int k=max(K,2);k<i;++k) 
			{
				ll rt=qroot(tp,k);
				if(qpow(rt,k)==tp)
				{
					fg=0;
					break;
				}
			}
			ans+=fg;
		}
	}
	write(ans);
	return 0;
}
