#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define M 400010
#define lson (rt<<1)
#define rson ((rt<<1)|1)
#define ll long long
using namespace std;
inline ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))
	{
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch))
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline void write(ll x)
{
    if(x<0)
	{
        putchar('-');
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
struct func
{
	ll k,b;
	friend func operator+(const func&a,const func&b)
	{
		func res;
		res.k=b.k+a.k;
		res.b=b.b+a.b;
		return res;
	}
	friend pair<func,ll> operator^(func a,func b)
	{
		if(a.k<b.k||(a.k==b.k&&a.b<b.b))swap(a,b);
	    if(a.b>=b.b){return make_pair(a,INF);}
	    return make_pair(b,(b.b-a.b)/(a.k-b.k));
	}
	func(){k=b=0;}
	func(ll _k,ll _b){k=_k,b=_b;}
};
ll tag[M<<3];
struct node
{
	func lmax,rmax,ans,sum;
	ll val;
	node operator+(const node&a)const
    {
        node res;
		res.val=min(val,a.val);
        auto tmp=lmax^(sum+a.lmax);
        res.lmax=tmp.first;
		res.val=min(res.val,tmp.second);
        tmp=a.rmax^(rmax+a.sum);
        res.rmax=tmp.first;
		res.val=min(res.val,tmp.second);
        tmp=ans^a.ans;
		res.val=min(res.val,tmp.second);
        tmp=tmp.first^(rmax+a.lmax);
        res.ans=tmp.first;
		res.val=min(res.val,tmp.second);
        res.sum=sum+a.sum;
        return res;
    }
}tr[M<<3];
ll val[M];
void update(ll rt)
{
	tr[rt]=tr[lson]+tr[rson];
}
void change(ll rt,ll v)
{
    tag[rt]+=v;
	tr[rt].val-=v;
    tr[rt].lmax.b+=tr[rt].lmax.k*v;
    tr[rt].rmax.b+=tr[rt].rmax.k*v;
    tr[rt].ans.b+=tr[rt].ans.k*v;
    tr[rt].sum.b+=tr[rt].sum.k*v;
}
void pushup(ll rt,ll l,ll r,ll v)
{
	if(v>tr[rt].val)
	{
		ll tmp=tag[rt]+v,mid=(l+r)>>1;
		tag[rt]=0;
		pushup(lson,l,mid,tmp);
		pushup(rson,mid+1,r,tmp);
		update(rt);
	}
	else change(rt,v);
}
void pushdown(ll rt)
{
	if(tag[rt])
	{
		ll t=tag[rt];
		tag[rt]=0;
		change(lson,t);
		change(rson,t);
	}
}
void build(ll rt,ll l,ll r)
{
	if(l==r)
	{
		auto dg=func(1,val[l]);
		tr[rt].lmax=tr[rt].rmax=tr[rt].ans=tr[rt].sum=dg;
		tr[rt].val=INF;
		return;
	}
	ll mid=(l+r)>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	update(rt);
}
void modify(ll rt,ll l,ll r,ll posl,ll posr,ll v)
{
	if(posl<=l&&r<=posr)
	{
		pushup(rt,l,r,v);
		return;
	}
	ll mid=(l+r)>>1;
	pushdown(rt);
	if(posl<=mid)modify(lson,l,mid,posl,posr,v);
	if(posr>mid)modify(rson,mid+1,r,posl,posr,v);
	update(rt);
}
node query(ll rt,ll l,ll r,ll posl,ll posr)
{
	if(posl<=l&&r<=posr)return tr[rt];
	ll mid=(l+r)>>1;
	pushdown(rt);
	if(posr<=mid)return query(lson,l,mid,posl,posr);
	if(posl>mid)return query(rson,mid+1,r,posl,posr);
	return query(lson,l,mid,posl,mid)+query(rson,mid+1,r,mid+1,posr);
}
int main()
{
	ll n=read(),q=read();
	for(ll i=1;i<=n;++i)val[i]=read();
	build(1,1,n); 
	for(ll i=1;i<=q;++i)
	{
		ll op=read(),l=read(),r=read();
		if(op==1)
		{
			ll x=read();
			modify(1,1,n,l,r,x);
		}
		else
		{
			auto ans=query(1,1,n,l,r);
			write(max(ans.ans.b,0ll)),putchar('\n');
		}
	}
	return 0;
}

