#include<bits/stdc++.h>
#define M 11451411
#define ll long long
using namespace std;
inline ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    if(ch=='#')exit(0);
    while(!isdigit(ch))
	{
		if(ch=='#')exit(0);
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
ll n,tmp,ans,phi[M],num[M],mod;
ll qpow(ll x,ll y,ll m)
{
	ll res=1;
	while(y)
	{
		if(y&1)res=res*x%m+m;
		y>>=1;
		x=x*x%m+m;
	}
	return res;
}
int main()
{
	int cases=0;
	while(true)
	{
		mod=read(),n=read();
		ans=1;
		phi[1]=mod;
		for(ll i=2;i<=n+114;i++)
		{
			tmp=phi[i-1];
			phi[i]=1;
			for(ll j=2;j*j<=tmp;j++)
			{
				if(tmp%j)continue;
				phi[i]*=j-1;
				tmp/=j;
				while(!(tmp%j))phi[i]*=j,tmp/=j;
			}
			if(tmp>1)phi[i]*=(tmp-1);
		}
		for(ll i=1;i<=n;i++)
		{
			scanf("%lld",&num[i]);
			if(phi[i]<num[i])num[i]=num[i]%phi[i]+phi[i];
		}
	    for(ll i=n;i>=1;i--)ans=qpow(num[i],ans,phi[i]);
		printf("Case #%lld: %lld\n",++cases,ans%mod);
	}
	return 0;
}
