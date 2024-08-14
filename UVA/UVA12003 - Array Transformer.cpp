#include<bits/stdc++.h>
#define M 11451411
#define ll long long 
using namespace std;
ll n,m,u,blen,block[M],num[M],b[M],s[M],lid[M],rid[M];
// block表示块的编号,blen为 block个数 
void change(ll p,ll k)
{
	int tmp=num[p];
	num[p]=k; //原数组修改
	for(int i=lid[block[p]];i<=rid[block[p]];i++)//b中找num[i],并将它修改
	{
		if(b[i]==tmp)
		{
			b[i]=k;
			break;
		}
	}
	sort(b+lid[block[p]],b+rid[block[p]]+1);
}
ll query(ll nl,ll nr,ll p)//区间查询
{   
	ll l=block[nl],r=block[nr],res=0;
	if(l==r)
	{ 
	    for(ll i=nl;i<=nr;i++)if(num[i]<p)res++;
	    return res;
	}
	for(ll i=nl;block[i]==l;i++)if(num[i]<p)res++;
	for(ll i=l+1;i<r;i++)res+=(lower_bound(b+lid[i],b+rid[i]+1,p)-b)-lid[i];
	for(ll i=nr;block[i]==r;i--)if(num[i]<p)res++;
	return res;
}
int main()
{
	scanf("%lld%lld%lld",&n,&m,&u);
	blen=sqrt(n);
	for(ll i=1;i<=n/blen;i++) lid[i]=(i-1)*blen+1,rid[i]=lid[i]+blen-1;
	rid[n/blen]=n;
	for(ll i=1;i<=n/blen;i++) 
		for(ll j=lid[i];j<=rid[i];j++)
			block[j]=i; //分块
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
	    b[i]=num[i];
	}
	for(ll i=1;i<=n/blen;i++)sort(b+lid[i],b+rid[i]+1);
	for(ll i=1,l,r,k,p,ans;i<=m;i++)
	{
		scanf("%lld%lld%lld%lld",&l,&r,&k,&p);
		ans=query(l,r,k);
		change(p,u*ans/(r-l+1));
	}
	for(ll i=1;i<=n;i++)printf("%lld\n",num[i]);
	return 0;
}
