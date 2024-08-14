#include<bits/stdc++.h>
#define lson rt<<1
#define rson rt<<1|1
#define M 114514
#define ll long long
using namespace std;
ll n,p,m,num[M];
struct node
{
	ll l,r,v,tag;
}tree[M*4];
void pushup(ll rt)
{
	tree[rt].v=tree[lson].v+tree[rson].v;
	tree[rt].tag=max(tree[lson].tag,tree[rson].tag);
}
void build(ll rt,ll l,ll r)
{
	tree[rt]={l,r,0,0};
	if(l==r)
	{
		tree[rt].v=tree[rt].tag=num[l];
		return;
	}
	ll mid=(l+r)>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	pushup(rt);
}
void modify(ll rt,ll l,ll r)
{
	if(tree[rt].l==tree[rt].r)
	{
		tree[rt].tag=sqrt(tree[rt].tag);
		tree[rt].v=sqrt(tree[rt].v);
		return;
	}
	ll mid=(tree[rt].l+tree[rt].r)>>1;
	if(l<=mid&&tree[lson].tag>1)modify(lson,l,r);
	if(r>mid&&tree[rson].tag>1)modify(rson,l,r);
	pushup(rt);
}
ll query(ll rt,ll l,ll r)
{
	if(tree[rt].l>=l&&tree[rt].r<=r)return tree[rt].v;
	ll mid=(tree[rt].l+tree[rt].r)>>1,res=0;
	if(l<=mid)res+=query(lson,l,r);
	if(r>mid)res+=query(rson,l,r);
	return res;
}
int main()
{
	scanf("%lld",&n);
    for(ll i=1;i<=n;i++)scanf("%lld",&num[i]);
	build(1,1,n);
	scanf("%lld",&m);
	for(ll i=1,k,l,r;i<=m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&r);
		if(l>r)swap(l,r);
		if(!k)modify(1,l,r);
		else printf("%lld\n",query(1,l,r));
	}
	return 0;
}
