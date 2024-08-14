#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define ft first
#define sd second
#define np nullptr
#define pn2 pair<node*,node*>
using namespace std;
ll m,n;
struct node
{
	node* l;
	node* r;
	ll v,key,cnt,size;
	bool to_rev=false;
	node(ll val):v(val),cnt(1),size(1)
	{
		l=r=np;
		key=rand();
	}
	ll combine()
	{
		size=cnt;
		if(l)size+=l->size;
		if(r)size+=r->size;
		return size;
	}
	void pushdown()
	{
		swap(l,r);
		if(l)l->to_rev^=1;
		if(r)r->to_rev^=1;
		to_rev=false;
	}
	void check_tag(){if(to_rev)pushdown();}	
};
node* rt;
pn2 split(node*k,ll size)
{
	if(!k)return mp(np,np);
	k->check_tag();
	pn2 tmp;
	if(size<=(!k->l?0:k->l->size))
	{
		tmp=split(k->l,size);
		k->l=tmp.sd;
		k->combine();
		return mp(tmp.ft,k);
	}
	else
	{
		tmp=split(k->r,size-(!k->l?0:k->l->size)-1);
		k->r=tmp.ft;
		k->combine();
		return mp(k,tmp.sd);
	}
}

node*merge(node*l,node*r)
{
	if(!l&&!r)return np;
	if(l&&!r)return l;
	if(!l&&r)return r;
	l->check_tag();
	r->check_tag();
	if(l->key<r->key)
	{
		l->r=merge(l->r,r);
		l->combine();
		return l;
	}
	else
	{
		r->l=merge(l,r->l);
		r->combine();
		return r;
	}
}
void insert(ll val)
{
	pn2 tmp=split(rt,val);
	pn2 lt=split(tmp.ft,val-1);
	node*nd;
	if(!lt.sd)nd=new node(val);
	rt=merge(merge(lt.ft,!lt.sd?nd:lt.sd),tmp.sd);
}
void seg_rev(ll l,ll r)
{
	pn2 x=split(rt,l-1);
	pn2 y=split(x.sd,r-l+1);
	y.ft->to_rev=true;
	rt=merge(x.ft,merge(y.ft,y.sd));
}
void print(node* k)
{
	if(!k)return;
	k->check_tag();
	print(k->l);
	printf("%lld ",k->v);
	print(k->r);
}
int main()
{
	srand(time(0));
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)insert(i);
	for(ll i=1,l,r;i<=m;i++)
	{
		scanf("%lld%lld",&l,&r);
		seg_rev(l,r);
    }
	print(rt);
}
