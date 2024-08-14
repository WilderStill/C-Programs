#include<bits/stdc++.h>
#define M 1000004
#define ll long long
#define INF 1e18
#define ls rt<<1
#define rs rt<<1|1
#define upbd(vec,val) (upper_bound(vec.begin(),vec.end(),val)-vec.begin()-1)
using namespace std;
struct node
{
    ll l,r,len,sum;
    vector<ll>c;
}tr[M<<2];
ll n,m,p,a[M];
void pushup(ll rt)
{
	tr[rt].sum=tr[ls].sum+tr[rs].sum;
	for(ll i=0,j=0;i<=tr[ls].len;++i)
	{
		if(j>tr[rs].len)--j;
		for(;j<=tr[rs].len;++j)
		{
			ll maxn=tr[ls].c[i+1]-1-i*p+tr[ls].sum;
			if(maxn<tr[rs].c[j]){if(j)--j;break;}
			ll res=tr[rs].c[j]+i*p-tr[ls].sum;
			tr[rt].c[i+j]=min(tr[rt].c[i+j],max(tr[ls].c[i],res));
		}
	}
}
void build(ll rt,ll l,ll r)
{
	tr[rt].l=l;
	tr[rt].r=r;
	tr[rt].len=r-l+1;
	for(ll i=l;i<=r+2;++i)tr[rt].c.push_back(INF);
	tr[rt].c[0]=-INF;
	if(l==r)
	{
		tr[rt].sum=a[l];
		tr[rt].c[1]=p-a[l];
		return;
	}
	ll mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(rt);
}
ll query(ll rt,ll l,ll r,ll x)
{
	if(tr[rt].l==l&&tr[rt].r==r)return x+tr[rt].sum-p*upbd(tr[rt].c,x);
	ll mid=(tr[rt].l+tr[rt].r)>>1;
	if(r<=mid)return query(ls,l,r,x);
	if(l>mid)return query(rs,l,r,x);
	return query(rs,mid+1,r,query(ls,l,mid,x));
}
int main()
{
    scanf("%lld%lld%lld",&n,&m,&p);
    for(ll i=1;i<=n;++i)scanf("%lld",&a[i]);
    build(1,1,n);
    for(ll i=1,l,r;i<=m;++i)
	{
		scanf("%lld%lld",&l,&r);
	    printf("%lld\n",query(1,l,r,0));
    }
    return 0;
}
