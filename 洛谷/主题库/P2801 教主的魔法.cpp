#include<bits/stdc++.h>
#define ll long long
#define M 1514514
using namespace std;
ll n,m,num[M],blen,block[M],mark[M];
vector<ll> v[M];
void update(ll p)//更新kuai数组
{
	v[p].clear(); 
	for(int i=(p-1)*blen+1;i<=p*blen;i++)v[p].push_back(num[i]);
	sort(v[p].begin(),v[p].end());
} 
void add(ll l,ll r,ll x)//区间修改 
{
	for(int i=l;i<=min(r,block[l]*blen);i++)num[i]+=x;
	update(block[l]);
	if(block[l]!=block[r])
	{
		for(int i=block[l]+1;i<block[r];i++)mark[i]+=x; 
		for(int i=(block[r]-1)*blen+1;i<=r;i++)num[i]+=x;		
		update(block[r]);
	}
}
ll query(ll nl,ll nr,ll k)
{
	ll l=block[nl],r=block[nr],res=0;
	if(l==r)
	{
		for(ll i=nl;i<=nr;i++)if(num[i]+mark[block[i]]>=k)res++;
		return res;
	}
	for(ll i=nl;i<=l*blen;i++)if(num[i]+mark[block[i]]>=k)res++;
	for(ll i=l+1;i<r;i++)res+=(v[i].end()-lower_bound(v[i].begin(),v[i].end(),k-mark[i]));
	for(ll i=(r-1)*blen+1;i<=nr;i++)if(num[i]+mark[block[i]]>=k)res++;
	return res;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	blen=sqrt(n);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
		block[i]=(i-1)/blen+1;
		v[block[i]].push_back(num[i]);
	}
	for(ll i=1;i<=block[n];i++)sort(v[i].begin(),v[i].end());
	for(ll i=1,l,r,k;i<=m;i++)
	{
		char op;
		cin>>op;
		scanf("%lld%lld%lld",&l,&r,&k);
		if(op=='A')
		{
			printf("%lld\n",query(l,r,k));
		}
		else add(l,r,k);
	}
	return 0;
}
