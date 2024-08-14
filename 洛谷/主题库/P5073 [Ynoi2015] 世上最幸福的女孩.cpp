#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define M 300010
#define lson (rt<<1)
#define rson ((rt<<1)|1)
#define ll long long
using namespace std;
inline ll readl()
{
    register ll x=0,f=1;
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
inline int read()
{
    register int x=0,f=1;
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
	if(a.b>=b.b){return make_pair(a,INF);}
	return make_pair(b,(b.b-a.b)/(a.k-b.k));
}
ll tag[M<<2];
struct node
{
	func lmax,rmax,ans,sum;
	ll val;
	node operator+(const node&a)const
    {
        node res;
		res.val=min(val,a.val);
        auto tmp=kxb(lmax,(sum+a.lmax));
        res.lmax=tmp.first;
		res.val=min(res.val,tmp.second);
        tmp=kxb(a.rmax,(rmax+a.sum));
        res.rmax=tmp.first;
		res.val=min(res.val,tmp.second);
        tmp=kxb(ans,a.ans);
		res.val=min(res.val,tmp.second);
        tmp=kxb(tmp.first,(rmax+a.lmax));
        res.ans=tmp.first;
		res.val=min(res.val,tmp.second);
        res.sum=sum+a.sum;
        return res;
    }
}tr[M<<2];
ll val[M],qans[M<<1];
inline void update(int rt)
{
	tr[rt]=tr[lson]+tr[rson];
}
inline void change(int rt,ll v)
{
    tag[rt]+=v;
	tr[rt].val-=v;
    tr[rt].lmax.b+=tr[rt].lmax.k*v;
    tr[rt].rmax.b+=tr[rt].rmax.k*v;
    tr[rt].ans.b+=tr[rt].ans.k*v;
    tr[rt].sum.b+=tr[rt].sum.k*v;
}
inline void pushup(int rt,int l,int r,ll v)
{
	if(v>tr[rt].val)
	{
		register ll tmp=tag[rt]+v;
		int mid=(l+r)>>1;
		tag[rt]=0;
		pushup(lson,l,mid,tmp);
		pushup(rson,mid+1,r,tmp);
		update(rt);
	}
	else change(rt,v);
}
inline void pushdown(int rt)
{
	if(tag[rt])
	{
		register ll t=tag[rt];
		tag[rt]=0;
		change(lson,t);
		change(rson,t);
	}
}
inline void build(int rt,int l,int r)
{
	if(l==r)
	{
		register auto dg=func(1,val[l]);
		tr[rt].lmax=tr[rt].rmax=tr[rt].ans=tr[rt].sum=dg;
		tr[rt].val=INF;
		return;
	}
	register int mid=(l+r)>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	update(rt);
}
inline void modify(int rt,int l,int r,int posl,int posr,ll v)
{
	if(posl<=l&&r<=posr)
	{
		pushup(rt,l,r,v);
		return;
	}
	register int mid=(l+r)>>1;
	pushdown(rt);
	if(posl<=mid)modify(lson,l,mid,posl,posr,v);
	if(posr>mid)modify(rson,mid+1,r,posl,posr,v);
	update(rt);
}
inline node query(int rt,int l,int r,int posl,int posr)
{
	if(posl<=l&&r<=posr)return tr[rt];
	register int mid=(l+r)>>1;
	pushdown(rt);
	if(posr<=mid)return query(lson,l,mid,posl,posr);
	if(posl>mid)return query(rson,mid+1,r,posl,posr);
	return query(lson,l,mid,posl,mid)+query(rson,mid+1,r,mid+1,posr);
}
struct mrmy
{
    ll x;
	int l,r,id;
    friend bool operator<(mrmy a,mrmy b){return a.x<b.x;}
}syh[M<<1];
ll sm;
int tot;
int main()
{
	int n=read(),q=read();
	for(register int i=1;i<=n;++i)val[i]=readl();
	for(register int i=1;i<=q;++i)
	{
		register int op=read();
		if(op==1)
		{
			register ll x=read();
			sm+=x;
		}
		else
		{
			register int l=read(),r=read();++tot;
			syh[tot]={sm,l,r,tot};
		}
	}
	sort(syh+1,syh+tot+1);
	sm=syh[1].x;
	for(register int i=1;i<=tot;++i)syh[i].x-=sm;
	//for(int i=1;i<=tot;++i)cout<<syh[i].id<<" "<<syh[i].l<<" "<<syh[i].r<<" "<<syh[i].x<<endl;
	for(register int i=1;i<=n;++i)val[i]+=sm;
	build(1,1,n); 
	for(register int i=1;i<=tot;++i)
	{
		modify(1,1,n,1,n,syh[i].x-syh[i-1].x);
		//modify(1,1,n,1,n,syh[i].x);
		auto ans=query(1,1,n,syh[i].l,syh[i].r);
		qans[syh[i].id]=max(ans.ans.b,0ll);
	}
	for(register int i=1;i<=tot;++i)
		write(qans[i]),puts("");
	return 0;
}
