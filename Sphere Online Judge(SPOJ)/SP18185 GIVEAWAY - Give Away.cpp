#include<bits/stdc++.h>
#define ll long long
#define M 514514
using namespace std;
ll n,m,num[M],blen,block[M];
vector<ll> v[M];
void change(ll p,ll k)
{
	ll tmp=block[p];
	num[p]=k;
	v[tmp].clear();
	for(int i=(tmp-1)*blen+1;i<=tmp*blen;i++)v[tmp].push_back(num[i]);
	sort(v[tmp].begin(),v[tmp].end());
	return ;
}
ll query(ll nl,ll nr,ll k)
{
	ll l=block[nl],r=block[nr],res=0;
	if(l==r)
	{
		for(ll i=nl;i<=nr;i++)if(num[i]>=k)res++;
		return res;
	}
	for(ll i=nl;i<=l*blen;i++)if(num[i]>=k)res++;
	for(ll i=l+1;i<r;i++)res+=(v[i].end()-lower_bound(v[i].begin(),v[i].end(),k));
	for(ll i=(r-1)*blen+1;i<=nr;i++)if(num[i]>=k)res++;
	return res;
}
int main()
{
	scanf("%lld",&n);
	blen=sqrt(n);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
		block[i]=(i-1)/blen+1;
		v[block[i]].push_back(num[i]);
	}
	for(ll i=1;i<=block[n];i++)sort(v[i].begin(),v[i].end());
	scanf("%lld",&m);
	for(ll i=1,op,l,r,k;i<=m;i++)
	{
		scanf("%lld",&op);
		if(op==0)
		{
			scanf("%lld%lld%lld",&l,&r,&k);
			printf("%lld\n",query(l,r,k));
		}
		else
		{
			scanf("%lld%lld",&r,&k);
			change(r,k);
		}
	}
	return 0;
}
