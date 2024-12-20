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
ll n,blen,num[M],blo[M],mk[M],mt[M];
ll mod=10007;
inline void update(int p)
{
    for(int i=(p-1)*blen+1;i<=min(p*blen,n);++i)num[i]=(num[i]*mt[p]%mod+mk[p])%mod;
    mk[p]=0,mt[p]=1;
}
inline void modify(bool op,ll pl,ll pr,ll k) 
{
	ll l=blo[pl],r=blo[pr];
	update(l);
	if(l==r)
	{
		for(int i=pl;i<=pr;++i)num[i]=op?(num[i]*k)%mod:(num[i]+k)%mod;
		return;
	}
	update(r);
	for(int i=pl;i<=l*blen;++i)num[i]=op?(num[i]*k)%mod:(num[i]+k)%mod;
	for(int i=l+1;i<r;++i)op?(mk[i]*=k)%=mod,(mt[i]*=k)%=mod:(mk[i]+=k)%=mod;
	for(int i=(r-1)*blen+1;i<=pr;++i)num[i]=op?(num[i]*k)%mod:(num[i]+k)%mod;
	return;
}
inline ll query(ll p)
{
	return (num[p]*mt[blo[p]]+mk[blo[p]])%mod;
}
int main()
{
	n=read();
	blen=sqrt(n);
	for(ll i=1;i<=n;++i)
	{
		num[i]=read();
		blo[i]=(i-1)/blen+1;
		mt[i]=1;
	}
	for(ll i=1;i<=n;++i)
	{
		ll op=read(),l=read(),r=read(),c=read();
		if(op==2)write(query(r)),puts("");
		else modify(op,l,r,c);
	}
	return 0;
}
