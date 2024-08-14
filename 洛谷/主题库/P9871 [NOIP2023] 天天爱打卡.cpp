#include<bits/stdc++.h>
#define M 200010
#define ll long long
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;
struct node
{
	ll l,r,maxn,tag;
}tr[M<<2];
inline void pushup(ll rt)
{
	tr[rt].maxn=max(tr[lson].maxn,tr[rson].maxn);
}
inline void build(ll rt,ll l,ll r)
{
	tr[rt].l=l,tr[rt].r=r,tr[rt].maxn=0,tr[rt].tag=0;
	if(l==r)return;
	ll mid=(l+r)>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	pushup(rt);
}
inline void update(ll rt,ll val)
{
	tr[rt].maxn+=val;
	tr[rt].tag+=val;
}
inline void pushdown(ll rt)
{
	if(tr[rt].tag)
	{
		update(lson,tr[rt].tag);
		update(rson,tr[rt].tag);
		tr[rt].tag=0;
	}
}
inline void modify(ll rt,ll posl,ll posr,ll val)
{
	if(posl<=tr[rt].l&&tr[rt].r<=posr)
	{
		update(rt,val);
		return;
	}
	pushdown(rt);
	if(posl<=tr[lson].r)modify(lson,posl,posr,val);
	if(posr>=tr[rson].l)modify(rson,posl,posr,val);
	pushup(rt);
}
inline ll query(ll rt,ll posl,ll posr)
{
	if(posl<=tr[rt].l&&tr[rt].r<=posr)return tr[rt].maxn;
	pushdown(rt);
	ll res=-0x3f3f3f3f3f3f3f3f;
	if(posl<=tr[lson].r)res=max(res,query(lson,posl,posr));
	if(posr>=tr[rson].l)res=max(res,query(rson,posl,posr));
	return res;
}
ll syh[M];
struct lnode
{
	ll l,r,val;
	bool operator<(const lnode&b)const{return r<b.r;}
}qj[M];
int main()
{
	int c,t;
	scanf("%d%d",&c,&t);
    while(t--)
    {
    	ll n,m,k,d,tot=0;
    	scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
		for(int i=1;i<=m;++i)
		{
			ll l,r,val;
			scanf("%lld%lld%lld",&r,&l,&val);
			qj[i].l=r-l,qj[i].r=r,qj[i].val=val;
			syh[++tot]=qj[i].l;
			syh[++tot]=qj[i].r;
		}
		build(1,1,tot);
		sort(syh+1,syh+tot+1);
		tot=unique(syh+1,syh+tot+1)-syh-1;
		for(int i=1;i<=m;++i)
		{
			qj[i].l=lower_bound(syh+1,syh+tot+1,qj[i].l)-syh; 
			qj[i].r=lower_bound(syh+1,syh+tot+1,qj[i].r)-syh;
		}
		sort(qj+1,qj+m+1);
		ll ans=0;
		int rt=1;
		for(int i=1;i<=tot;++i)
		{
			modify(1,1,i,-d*(syh[i]-syh[i-1]));
			while(rt<=m&&qj[rt].r==i)modify(1,1,qj[rt].l+1,qj[rt].val),++rt;
			ans=max(ans,query(1,lower_bound(syh+1,syh+tot+1,syh[i]-k)-syh+1,i));
			if(i+1<tot)modify(1,i+2,i+2,ans); 
		}
		printf("%lld\n",ans);
	}
    return 0;
}
