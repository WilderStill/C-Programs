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
ll n,blen,num[M],blo[M],mk[M];
vector<ll>v[M];
inline void update(ll p)
{
	v[p].clear(); 
	for(int i=(p-1)*blen+1;i<=p*blen;++i)v[p].push_back(num[i]);
	sort(v[p].begin(),v[p].end());
} 
inline void modify(ll l,ll r,ll x) 
{
	for(int i=l;i<=min(r,blo[l]*blen);++i)num[i]+=x;
	update(blo[l]);
	if(blo[l]!=blo[r])
	{
		for(int i=blo[l]+1;i<blo[r];++i)mk[i]+=x; 
		for(int i=(blo[r]-1)*blen+1;i<=r;++i)num[i]+=x;		
		update(blo[r]);
	}
}
inline ll query(ll pl,ll pr,ll k)
{
	ll l=blo[pl],r=blo[pr],res=0;
	if(l==r)
	{
		for(ll i=pl;i<=pr;++i)if(num[i]+mk[blo[i]]<k)++res;
		return res;
	}
	for(ll i=pl;i<=l*blen;++i)if(num[i]+mk[blo[i]]<k)++res;
	for(ll i=l+1;i<r;++i)res+=(lower_bound(v[i].begin(),v[i].end(),k-mk[i])-v[i].begin());
	for(ll i=(r-1)*blen+1;i<=pr;++i)if(num[i]+mk[blo[i]]<k)++res;
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
		v[blo[i]].push_back(num[i]);
	}
	for(ll i=1;i<=blo[n];++i)sort(v[i].begin(),v[i].end());
	for(ll i=1;i<=n;++i)
	{
		ll op=read(),l=read(),r=read(),c=read();
		if(op)write(query(l,r,c*c)),puts("");
		else modify(l,r,c);
	}
	return 0;
}
