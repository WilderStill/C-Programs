#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define INFF 0x3f3f3f3f3f3f3f3f
#define M 100010
#define lson (rt<<1)
#define rson (rt<<1|1)
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
ll kray(ll x,ll y)
{
	if(x<0)return -((-x)/y);
	if(!x)return 0;
	return (x-1)/y+1;
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
	friend func operator^(const func&a,const pair<ll,ll>&x)
	{
		func res;
		if(x.first>x.second)
		{
			res.b=a.b+x.first*a.k;
			res.k=0;
		}
		else 
		{
			res.b=a.b;
			res.k=a.k;
		}
		return res;
	}
	void relay(ll&x,ll minn,func a)
	{
		if(k<a.k)
		{
			ll val=kray(b-a.b+1,a.k-k);
			if(val>minn&&x>val)x=val;
		}
	}
	func(){k=b=0;}
	func(ll _k,ll _b){k=_k,b=_b;}
	ll value(ll x){return k*x+b;}
};
struct node
{
	ll l,r,tag,minn,smin,rev;
	func sum,lmax[2],rmax[2],tmax[3];
	friend node operator+(const node a,const node b)
	{
		node res;
		res.l=a.l,res.r=b.r;
		res.tag=-INF;
		res.minn=min(a.minn,b.minn);
		res.smin=min(a.smin,b.smin);
		if(res.minn<a.minn)res.smin=min(res.smin,a.minn);
		if(res.minn<b.minn)res.smin=min(res.smin,b.minn);
		res.sum=(a.sum^make_pair(a.minn,res.minn))+(b.sum^make_pair(b.minn,res.minn));
		res.lmax[0]=(a.lmax[0]^make_pair(a.minn,res.minn));
		res.lmax[1]=(a.sum^make_pair(a.minn,res.minn))+(b.lmax[0]^make_pair(b.minn,res.minn));
		res.rmax[0]=(b.rmax[0]^make_pair(b.minn,res.minn));
		res.rmax[1]=(b.sum^make_pair(b.minn,res.minn))+(a.rmax[0]^make_pair(a.minn,res.minn));
		res.tmax[0]=(a.tmax[0]^make_pair(a.minn,res.minn));
		res.tmax[1]=(b.tmax[0]^make_pair(b.minn,res.minn));
		res.tmax[2]=(a.rmax[0]^make_pair(a.minn,res.minn))+(b.lmax[0]^make_pair(b.minn,res.minn));
		res.clear();
		res.rev=min({res.rev,a.rev,b.rev});
		return res;
	}
	void clear()
	{
		if(lmax[0].value(minn)<lmax[1].value(minn))swap(lmax[0],lmax[1]);
		if(rmax[0].value(minn)<rmax[1].value(minn))swap(rmax[0],rmax[1]);
		if(tmax[0].value(minn)<tmax[1].value(minn))swap(tmax[0],tmax[1]);
		if(tmax[0].value(minn)<tmax[2].value(minn))swap(tmax[0],tmax[2]);
		rev=INFF;
		lmax[0].relay(rev,minn,lmax[1]);
		rmax[0].relay(rev,minn,rmax[1]);
		tmax[0].relay(rev,minn,tmax[1]);
		tmax[0].relay(rev,minn,tmax[2]);
	}
}tr[M<<3];
ll val[M];
void update(ll rt)
{
	tr[rt]=tr[lson]+tr[rson];
}
void pushdown(ll rt)
{
	if(tr[rt].tag!=-INF)
	{
		tr[lson].tag=max(tr[lson].tag,tr[rt].tag);
		tr[lson].minn=max(tr[lson].minn,tr[rt].tag);
		tr[rson].tag=max(tr[rson].tag,tr[rt].tag);
		tr[rson].minn=max(tr[rson].minn,tr[rt].tag);
		tr[rt].tag=-INF;
	}
}
void build(ll rt,ll l,ll r)
{
	if(l==r)
	{
		tr[rt].l=tr[rt].r=l;
		tr[rt].tag=-INF;
		tr[rt].minn=val[l];
		tr[rt].smin=INF;
		tr[rt].sum=tr[rt].lmax[0]=tr[rt].rmax[0]=tr[rt].tmax[0]=func(1,0);
		tr[rt].lmax[1]=tr[rt].rmax[1]=tr[rt].tmax[1]=func(0,0);
		tr[rt].tmax[2]=func(0,-INFF);
		tr[rt].clear();
		return;
	}
	ll mid=(l+r)>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	update(rt);
}
void modify(ll rt,ll l,ll r,ll v)
{
	if(tr[rt].minn>=v)return;
	if(l<=tr[rt].l&&tr[rt].r<=r&&v<tr[rt].smin&&v<tr[rt].rev)
	{
		tr[rt].tag=tr[rt].minn=v;
		return;
	}
	if (tr[rt].l==tr[rt].r)
	{
		tr[rt].minn=v;
		tr[rt].clear();
		return;
	}
	ll mid=(tr[rt].l+tr[rt].r)>>1;
	pushdown(rt);
	if(l<=mid)modify(lson,l,r,v);
	if(r>mid)modify(rson,l,r,v);
	update(rt);
}
node query(ll rt,ll l,ll r)
{
	if(l<=tr[rt].l&&tr[rt].r<=r)return tr[rt];
	ll mid=(tr[rt].l+tr[rt].r)>>1;
	pushdown(rt);
	if(r<=mid)return query(lson,l,r);
	if(l>mid)return query(rson,l,r);
	return query(lson,l,r)+query(rson,l,r);
}
int main()
{
	ll n=read(),q=read();
	for(ll i=1;i<=n;++i)val[i]=read();
	build(1,1,n); 
	for(ll i=1;i<=q;++i)
	{
		ll op=read(),l=read(),r=read();
		if(!op)
		{
			ll x=read();
			modify(1,l,r,x);
		}
		else
		{
			auto ans=query(1,l,r);
			write(ans.tmax[0].value(ans.minn)),putchar('\n');
		}
	}
	return 0;
}
