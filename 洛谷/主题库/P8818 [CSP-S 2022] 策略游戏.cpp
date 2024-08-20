#include<bits/stdc++.h>
#define lson rt<<1
#define rson rt<<1|1
#define M 300010
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
ll n,m,q,val[2][M];
struct node
{
	ll l,r,nmax,pmax,nmin,pmin,tag;
	node operator+(const node&b)
	{
		node res;
		res.l=l,res.r=b.r,res.tag=(tag||b.tag);
		res.pmin=min(pmin,b.pmin),res.pmax=max(pmax,b.pmax);
		res.nmin=min(nmin,b.nmin),res.nmax=max(nmax,b.nmax);
		return res;
	}
}tr[2][M<<2];
void build(ll id,ll rt,ll l,ll r)
{
	tr[id][rt].l=l,tr[id][rt].r=r;
	if(l==r)
	{
		if(!val[id][l])tr[id][rt].tag=1;
		else if(val[id][l]>0)
		{
			tr[id][rt].pmax=tr[id][rt].pmin=val[id][l];
			tr[id][rt].nmin=INF,tr[id][rt].nmax=-INF;
		}
		else
		{
			tr[id][rt].nmax=tr[id][rt].nmin=val[id][l];
			tr[id][rt].pmin=INF,tr[id][rt].pmax=-INF;
		}
		return;
	}
	ll mid=(l+r)>>1;
	build(id,lson,l,mid);
	build(id,rson,mid+1,r);
	tr[id][rt]=tr[id][lson]+tr[id][rson];
}
node query(ll id,ll rt,ll l,ll r)
{
	ll posl=tr[id][rt].l,posr=tr[id][rt].r;
	if(posr<l||posl>r)return (node){0,0,0,0,0,0,0};
	if(l<=posl&&posr<=r)return tr[id][rt];
	node lq=query(id,lson,l,r),rq=query(id,rson,l,r);
	return !lq.l?rq:(!rq.l?lq:lq+rq);
}
int main()
{
	scanf("%lld%lld%lld",&n,&m,&q);
	for(ll i=1;i<=n;++i)scanf("%lld",&val[0][i]);
	for(ll i=1;i<=m;++i)scanf("%lld",&val[1][i]);
	build(0,1,1,n),build(1,1,1,n);
	for(ll i=1,l1,r1,l2,r2;i<=q;++i)
	{
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		auto x=query(0,1,l1,r1),y=query(1,1,l2,r2);
		if(y.nmin<0&&y.pmax>0)
		{
			if(x.tag)puts("0");
			else if(x.nmin<0&&x.pmax>0)printf("%lld\n",max(x.pmin*y.nmin,x.nmax*y.pmax));
			else if(x.nmin<0)printf("%lld\n",x.nmax*y.pmax);
			else printf("%lld\n",x.pmin*y.nmin);
		}
		else if(y.nmin<0)
		{
			if(x.nmin<0)printf("%lld\n",y.tag?0:x.nmin*y.nmax);
			else printf("%lld\n",x.tag?0:x.pmin*y.nmin);
		}
		else if(y.pmax>0)
		{
			if(x.pmax>0)printf("%lld\n",y.tag?0:x.pmax*y.pmin);
			else printf("%lld\n",x.tag?0:x.nmax*y.pmax);
		}
		else puts("0");
	}
    return 0;
}
