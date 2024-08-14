#include<bits/stdc++.h>
#define M 114514
#define ll long long
using namespace std;
ll n,m,blen,lastans,tot;
ll num[M],mode[1145][1145],w[M],cnt[M],block[M];
vector<ll>v[M];
map<ll,ll>mp;
void find_mode(ll k)
{
	ll maxn=0,res=0;
	memset(cnt,0,sizeof(cnt));
	for(ll i=(k-1)*blen+1;i<=n;i++)
	{
		cnt[num[i]]++;
		if(cnt[num[i]]>maxn||(cnt[num[i]]==maxn&&w[num[i]]<w[res])){res=num[i];maxn=cnt[res];}
		mode[k][block[i]]=res;
	}
}
ll f(ll l,ll r,ll sth){return upper_bound(v[sth].begin(),v[sth].end(),r)-lower_bound(v[sth].begin(),v[sth].end(),l);}
ll query(ll l,ll r)
{
	ll res=mode[block[l]+1][block[r]-1],maxn=f(l,r,mode[block[l]+1][block[r]-1]);
	for(ll i=l;i<=min(block[l]*blen,r);i++)
	{
		ll fr=f(l,r,num[i]);
        if(fr>maxn||(fr==maxn&&w[num[i]]<w[res]))res=num[i],maxn=fr;
	}
	if(block[l]==block[r])return res;
	for(ll i=(block[r]-1)*blen+1;i<=r;i++)
	{
		ll fr=f(l,r,num[i]);
        if(fr>maxn||(fr==maxn&&w[num[i]]<w[res]))res=num[i],maxn=fr;
	}
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
		if(!mp[num[i]]){mp[num[i]]=++tot;w[tot]=num[i];}
		num[i]=mp[num[i]];
		v[num[i]].push_back(i);
	}
	for(ll i=1;i<=block[n];i++)find_mode(i);
	for(ll i=1,l,r;i<=m;i++)
	{
		scanf("%lld%lld",&l,&r);
		l=(l+lastans-1)%n+1,r=(r+lastans-1)%n+1;
		if(l>r)swap(l,r);
		lastans=w[query(l,r)];
		printf("%lld\n",lastans);
	}
	return 0;
}
