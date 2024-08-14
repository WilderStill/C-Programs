#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define M 200010
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
	func(){k=b=0;}
	func(ll _k,ll _b){k=_k,b=_b;}
};
inline pair<func,ll>kxb(func a,func b)
{
	if(a.k<b.k||(a.k==b.k&&a.b<b.b))swap(a,b);
	if(a.b>=b.b)return make_pair(a,INF);
	return make_pair(b,(b.b-a.b)/(a.k-b.k));
}
ll tag[M<<2];
struct node
{
	func ans;
	ll val;
	node operator+(const node&a)const
    {
        node res;
		res.val=min(val,a.val);
        auto tmp=kxb(ans,a.ans);
		res.val=min(res.val,tmp.second);
        res.ans=tmp.first;
        return res;
    }
}tr[M<<2];
ll val[M];
inline void update(ll rt)
{
	tr[rt]=tr[lson]+tr[rson];
}
inline void change(ll rt,ll v)
{
    tag[rt]+=v;
	tr[rt].val-=v;
    tr[rt].ans.b+=tr[rt].ans.k*v;
}
inline void pushup(ll rt,ll l,ll r,ll v)
{
	if(v>tr[rt].val)
	{
		ll tmp=tag[rt]+v;
		ll mid=(l+r)>>1;
		tag[rt]=0;
		pushup(lson,l,mid,tmp);
		pushup(rson,mid+1,r,tmp);
		update(rt);
	}
	else change(rt,v);
}
inline void pushdown(ll rt)
{
	if(tag[rt])
	{
		ll t=tag[rt];
		tag[rt]=0;
		change(lson,t);
		change(rson,t);
	}
}
inline void build(ll rt,ll l,ll r)
{
	if(l==r)
	{
		auto dg=func(val[l],0);
		tr[rt].ans=dg;
		tr[rt].val=INF;
		return;
	}
	ll mid=(l+r)>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	update(rt);
}
inline void modify(ll rt,ll l,ll r,ll posl,ll posr,ll v)
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
inline node query(ll rt,ll l,ll r,ll posl,ll posr)
{
	if(posl<=l&&r<=posr)return tr[rt];
	ll mid=(l+r)>>1;
	pushdown(rt);
	if(posr<=mid)return query(lson,l,mid,posl,posr);
	if(posl>mid)return query(rson,mid+1,r,posl,posr);
	return query(lson,l,mid,posl,mid)+query(rson,mid+1,r,mid+1,posr);
}
pair<ll,ll>syh[M];
int main()
{
	ll n=read(),tot=0;
	for(ll i=1;i<=n;++i)
	{
		syh[i].first=read();
		syh[i].second=read();
		val[++tot]=syh[i].second;
	}
	sort(syh+1,syh+n+1);
	sort(val+1,val+tot+1);
	tot=unique(val+1,val+tot+1)-val-1;
	for(ll i=1;i<=n;++i)syh[i].second=lower_bound(val+1,val+tot+1,syh[i].second)-val;
	build(1,1,tot);
	ll ans=0,cnt=n;
	for(ll i=1;i<=n;++i)
	{
		ans=max(ans,cnt*syh[i].first+tr[1].ans.b);
		ll dg=i;
		do
		{
			--cnt;
			modify(1,1,tot,1,syh[dg].second,1);
			++dg;
		}while(dg<=n&&syh[dg].first==syh[i].first);
		i=dg-1;
	}
	write(ans);
}
