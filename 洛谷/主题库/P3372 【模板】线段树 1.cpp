#include<bits/stdc++.h>
#define M 100010
#define ll long long
#define lson rt<<1
#define rson rt<<1|1
using namespace std;
struct Segment_Tree
{
	ll sum,tag;
}tr[M<<2];
int n,m;
ll val[M];
void pushdown(int rt,int l,int r,ll v)
{
	tr[rt].sum+=v*(r-l+1);
	tr[rt].tag+=v;
}
void build(int rt,int l,int r)
{
	if(l==r)
	{
		tr[rt].sum=val[l];
		return;
	}
	int mid=(l+r)>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	tr[rt].sum=tr[lson].sum+tr[rson].sum;
}
void update(int rt,int nowl,int nowr,int l,int r,ll v)
{
	if(nowl<=l&&r<=nowr)
	{
		pushdown(rt,l,r,v);
		return;
	}
	int mid=(l+r)>>1;
	if(tr[rt].tag) 
	{
		pushdown(lson,l,mid,tr[rt].tag);
		pushdown(rson,mid+1,r,tr[rt].tag);
		tr[rt].tag=0;
	}
	if(nowl<=mid)update(lson,nowl,nowr,l,mid,v);
	if(nowr>mid)update(rson,nowl,nowr,mid+1,r,v);
	tr[rt].sum=tr[lson].sum+tr[rson].sum;
}
ll query(int rt,int nowl,int nowr,int l,int r)
{
	if(nowl<=l&&r<=nowr)return tr[rt].sum;
	ll res=0;
	int mid=(l+r)>>1;
	if(tr[rt].tag) 
	{
		pushdown(lson,l,mid,tr[rt].tag);
		pushdown(rson,mid+1,r,tr[rt].tag);
		tr[rt].tag=0;
	}
	if(nowl<=mid)res+=query(lson,nowl,nowr,l,mid);
	if(nowr>mid)res+=query(rson,nowl,nowr,mid+1,r);
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%lld",&val[i]);
	build(1,1,n);
	for(int i=1,op;i<=m;++i)
	{
		scanf("%d",&op);
		if(op==1)
		{
			int x,y;ll v;
			scanf("%d%d%lld",&x,&y,&v);
			update(1,x,y,1,n,v);
		}
		else
		{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%lld\n",query(1,x,y,1,n));
		}
	}
	return 0;
}
