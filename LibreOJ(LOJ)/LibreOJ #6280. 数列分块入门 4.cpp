#include<bits/stdc++.h>
#define ll long long
#define M 1514514
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
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
ll n,blen,num[M],sum[M],blo[M],mk[M];
inline void modify(ll pl,ll pr,ll k) 
{
	ll l=blo[pl],r=blo[pr];
	if(l==r)
	{
		for(int i=pl;i<=pr;++i)num[i]+=k,sum[blo[i]]+=k;
		return;
	}
	for(int i=pl;i<=l*blen;++i)num[i]+=k,sum[blo[i]]+=k;
	for(int i=l+1;i<r;++i)mk[i]+=k,sum[i]+=blen*k;
	for(int i=(r-1)*blen+1;i<=pr;++i)num[i]+=k,sum[blo[i]]+=k;
}
inline ll query(ll pl,ll pr,ll mod)
{
	ll l=blo[pl],r=blo[pr],res=0;
	if(l==r)
	{
		for(ll i=pl;i<=pr;++i)res=(res+num[i]+mk[blo[i]])%mod;
		return res;
	}
	for(ll i=pl;i<=l*blen;++i)res=(res+num[i]+mk[blo[i]])%mod;
	for(ll i=l+1;i<r;++i)res=(res+sum[i])%mod;
	for(ll i=(r-1)*blen+1;i<=pr;++i)res=(res+num[i]+mk[blo[i]])%mod;
	return res;
}
int main()
{
	n=read();
	blen=sqrt(n);
	for(ll i=1;i<=n;++i)
	{
		num[i]=read();
		blo[i]=(i-1)/blen+1;
		sum[blo[i]]+=num[i];
	}
	for(ll i=1;i<=n;++i)
	{
		ll op=read(),l=read(),r=read(),c=read();
		if(op)write(query(l,r,c+1)),puts("");
		else modify(l,r,c);
	}
	return 0;
}
