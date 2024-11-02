#include<bits/stdc++.h>
typedef long long ll;
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
namespace Wilder_Math
{
	typedef long long ll;
	const int M=1000010;
	inline ll qpow(ll x,ll y,ll mod)
	{
		ll res=1;
		while(y)
		{
			if(y&1)res=res*x%mod;
			x=x*x%mod;
			y>>=1;
		}
		return res;
	}
	inline ll tmul(ll x,ll y,ll mod)
	{
		ll res=0;
	    while(y)
	    {
	        if(y&1)res=(res+x)%mod;
	        x=(x+x)%mod;
	        y>>=1;
	    }
	    return res;
	}
	inline ll exgcd(ll a,ll b,ll&x,ll&y)
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
	inline ll getphi(ll x)
	{
		ll res=1;
		for(ll i=2;i*i<=x;++i) 
		{
			ll tp=1;
			if(!(x%i))
			{
	        	tp=i-1,x/=i;
				while(!(x%i))tp*=i,x/=i;
			}
			res*=tp;
		}
		if(x^1)res*=(x-1);
		return res;
	}
	inline ll exEuler(ll x,ll y,ll mod)
	{
		ll nmod=getphi(mod);
		return qpow(x,y%nmod,mod);
	}
	inline ll excrt(ll n,ll a[],ll b[])
	{
	    ll res=a[1],mod=b[1];
	    for(ll i=2,x,y;i<=n;++i)
	    {
	        ll dt=(a[i]-res%b[i]+b[i])%b[i],gcd=exgcd(mod,b[i],x,y),tp=b[i]/gcd;
	        if(dt%gcd)return -1;
	        x=tmul(x,dt/gcd,tp);
	        res+=x*mod;
	        mod*=tp;
			res=(res%mod+mod)%mod;
	    }
	    return (res%mod+mod)%mod;
	}
	ll Primetot,num[M];bool notPrime[M];
	inline void Eulerphi(ll n,ll&Primetot,ll *Prime,ll *phi,ll *d)
	{
	    d[1]=1;
		for(ll i=2;i<=n;++i) 
		{
			if(!notPrime[i])Prime[++Primetot]=i,phi[i]=i-1,num[i]=1,d[i]=2;
			for(ll j=1;j<=Primetot&&i*Prime[j]<=n;++j)
			{
				notPrime[Prime[j]*i]=1;
				if(i%Prime[j]==0)
				{
					phi[i*Prime[j]]=phi[i]*Prime[j];
					num[i*Prime[j]]=num[i]+1;
					d[i*Prime[j]]=d[i]/(num[i]+1)*(num[i*Prime[j]]+1);
					break;
				}
				phi[i*Prime[j]]=phi[i]*(Prime[j]-1);
				num[i*Prime[j]]=1;
	            d[i*Prime[j]]=d[i]<<1;
			}
		}
	}
	inline ll getfact(ll n,ll&cnt,ll p,ll mod)
	{
		if(!n)return 1;
		ll res=1;
		for(ll i=2;i<=mod;++i)if(i%p)(res*=i)%=mod;
		res=qpow(res,n/mod,mod);
		cnt+=n/p;
		for(ll i=2;i<=n%mod;++i)if(i%p)(res*=i)%=mod;
		return res*getfact(n/p,cnt,p,mod)%mod;
	}
	inline ll C(ll n,ll m,ll p,ll mod)
	{
		if(m>n)return 0;
		ll cnt1=0,cnt2=0,cnt3=0;
		ll p1=getfact(n,cnt1,p,mod),p2=getfact(m,cnt2,p,mod),p3=getfact(n-m,cnt3,p,mod);
		if(cnt1-cnt2-cnt3>0)
		{
			ll tp=qpow(p,cnt1-cnt2-cnt3,mod);
			if(tp>=mod)return 0;
			p1=p1*tp%mod;
		}
		ll x,y;
		exgcd(p2*p3%mod,mod,x,y);
		return p1*x%mod;
	}
	ll a[M],b[M],cnt;
	inline ll exLucas(ll n,ll m,ll mod)
	{
		ll x=mod;
		for(ll i=2;i*i<=mod;++i)
		{
			ll tp=1;
			if(!(x%i))
			{
				while(!(x%i))tp*=i,x/=i;
				a[++cnt]=tp,b[cnt]=C(n,m,i,tp);
			}
		}
		if(x^1)a[++cnt]=x,b[cnt]=C(n,m,x,x);
		return excrt(cnt,b,a);
	}
}
using namespace Wilder_Math;
int main()
{
	ll n=read(),m=read(),p=read();
	write(exLucas(n,m,p));
    return 0;
}
