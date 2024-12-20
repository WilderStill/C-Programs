#include<bits/stdc++.h>
using namespace std;
namespace Wilder_Arithmetical
{
	typedef long long ll;
	const int M=1000010;
	__int128 one=1;
	inline ll qpow(ll x,ll y)
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
	inline ll qpow_mod(ll x,ll y,ll mod)
	{
		ll res=1;
		while(y)
		{
			if(y&1)res=one*res*x%mod;
			x=one*x*x%mod;
			y>>=1;
		}
		return res;
	}
	inline ll getroot(ll n,ll k)
	{
		ll l=1,r=n,res;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(qpow(mid,k)<=n)l=mid+1,res=mid;
			else r=mid-1;
		}
		return res;
	}
	inline ll smul(ll x,ll y,ll mod)
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
	inline ll Binary_gcd(ll x,ll y)
	{
		if(!x)return y;
		if(!y)return x;
		if(x<y)swap(x,y);
	    ll Binx=__builtin_ctz(x),Biny=__builtin_ctz(y),minn=Binx<Biny?Binx:Biny,del;
	    y>>=Biny;
	    while(x)
	    {
	        x>>=Binx;
	        del=y-x;
	        Binx=__builtin_ctz(del);
	        if(x<y)y=x;
	        x=del<0?-del:del;
	    }
	    return y<<minn;
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
	inline ll divide(ll x,ll *prime,ll *cnt)
	{
		ll cp=0;
		for(ll i=2;i*i<=x;++i)
		{
			if(!(x%i))
			{
	        	prime[++cp]=i,++cnt[cp],x/=i;
				while(!(x%i))++cnt[cp],x/=i;
			}
		}
		if(x^1)prime[++cp]=x,++cnt[cp];
		return cp;
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
		return qpow_mod(x,y%nmod,mod);
	}
	inline ll excrt(ll n,ll a[],ll b[])
	{
	    ll res=a[1],mod=b[1];
	    for(ll i=2,x,y;i<=n;++i)
	    {
	        ll dt=(a[i]-res%b[i]+b[i])%b[i],gcd=exgcd(mod,b[i],x,y),tp=b[i]/gcd;
	        if(dt%gcd)return -1;
	        x=smul(x,dt/gcd,tp);
	        res+=x*mod;
	        mod*=tp;
			res=(res%mod+mod)%mod;
	    }
	    return (res%mod+mod)%mod;
	}
	ll Prime[M],d[M],tnum[M],phi[M],mu[M],facsum[M],tg[M];
	/*
		Prime--质数,d--约数个数,mu--莫比乌斯函数,phi--欧拉函数
		tnum--最小质因子出现次数,facsum--约数和,tg--最小质因子的Σ1-k p^i
	*/
	bool notPrime[M];
	inline ll Eulerphi(ll n)
	{
	    ll Primetot=0;
		d[1]=mu[1]=tg[1]=facsum[1]=1;
		for(ll i=2;i<=n;++i) 
		{
			if(!notPrime[i])
			{
				Prime[++Primetot]=i;
				phi[i]=i-1;
				mu[i]=-1;
				tnum[i]=1;
				d[i]=2;
				tg[i]=facsum[i]=i+1;
			}
			for(ll j=1;j<=Primetot&&i*Prime[j]<=n;++j)
			{
				notPrime[Prime[j]*i]=1;
				if(i%Prime[j]==0)
				{
					phi[i*Prime[j]]=phi[i]*Prime[j];
					mu[i*Prime[j]]=0;
					tnum[i*Prime[j]]=tnum[i]+1;
					d[i*Prime[j]]=d[i]/(tnum[i]+1)*(tnum[i*Prime[j]]+1);
					tg[i*Prime[j]]=tg[i]*Prime[j]+1;
        			facsum[i*Prime[j]]=facsum[i]/tg[i]*tg[i*Prime[j]];
					break;
				}
				phi[i*Prime[j]]=phi[i]*(Prime[j]-1);
				mu[i*Prime[j]]=-mu[i];
				tnum[i*Prime[j]]=1;
	            d[i*Prime[j]]=d[i]<<1;
	            facsum[i*Prime[j]]=facsum[i]*facsum[Prime[j]];
				tg[i*Prime[j]]=Prime[j]+1;
			}
		}
		return Primetot;
	}
	inline ll Lucas_C(ll n,ll m,ll mod)
	{
		if(n<m)return 0;
		if(m>n-m)m=n-m;
		ll x=1,y=1;
		for(int i=0;i<m;++i)
		{
			x=(x*(n-i))%mod;
			y=(y*(i+1))%mod;
		}
		return x*qpow_mod(y,mod-2,mod)%mod;
	}
	inline ll Lucas(ll n,ll m,ll mod)
	{
		if(!m)return 1;
		return Lucas(n/mod,m/mod,mod)*Lucas_C(n%mod,m%mod,mod)%mod;
	}
	inline ll getfact(ll n,ll&cnt,ll p,ll mod)
	{
		if(!n)return 1;
		ll res=1;
		for(ll i=2;i<=mod;++i)if(i%p)(res*=i)%=mod;
		res=qpow_mod(res,n/mod,mod);
		cnt+=n/p;
		for(ll i=2;i<=n%mod;++i)if(i%p)(res*=i)%=mod;
		return res*getfact(n/p,cnt,p,mod)%mod;
	}
	inline ll exLucas_C(ll n,ll m,ll p,ll mod)
	{
		if(m>n)return 0;
		ll cnt1=0,cnt2=0,cnt3=0;
		ll p1=getfact(n,cnt1,p,mod),p2=getfact(m,cnt2,p,mod),p3=getfact(n-m,cnt3,p,mod);
		if(cnt1-cnt2-cnt3>0)
		{
			ll tp=qpow_mod(p,cnt1-cnt2-cnt3,mod);
			if(tp>=mod)return 0;
			p1=p1*tp%mod;
		}
		ll x,y;
		exgcd(p2*p3%mod,mod,x,y);
		return p1*x%mod;
	}
	ll exLucas_a[M],exLucas_b[M];
	inline ll exLucas(ll n,ll m,ll mod)
	{
		ll x=mod,cnt=0;
		for(ll i=2;i*i<=mod;++i)
		{
			ll tp=1;
			if(!(x%i))
			{
				while(!(x%i))tp*=i,x/=i;
				exLucas_a[++cnt]=tp,exLucas_b[cnt]=exLucas_C(n,m,i,tp);
			}
		}
		if(x^1)exLucas_a[++cnt]=x,exLucas_b[cnt]=exLucas_C(n,m,x,x);
		return excrt(cnt,exLucas_b,exLucas_a);
	}
}
using namespace Wilder_Arithmetical;
ll n;
vector<ll>dk;
int main()
{
    int T,cases=0;
    scanf("%lld",&T);
    while(T--)
	{
		scanf("%lld",&n);
		n=n/__gcd(n,2ll)*9;
	    ll phi=getphi(n);
	    for(ll i=1;i*i<=phi;++i)
			if(!(phi%i))
				dk.push_back(i),dk.push_back(phi/i);
	    sort(dk.begin(),dk.end());
	    bool fg=0;
	    for(auto i:dk)
	        if(qpow_mod(10,i,n)==1)
	        {
	            printf("%lld\n",i);
				fg=1;
				break;
	        }
	    if(!fg)puts("-1");
	}
    return 0;
}

