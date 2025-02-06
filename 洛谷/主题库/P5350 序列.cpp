#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch&15);ch=getchar();}
	return x*f;
}
inline void write(ll x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
	return;
}
constexpr int M=3000010;
constexpr ll mod=1e9+7;
mt19937_64 dg(time(0));
int root,n,m,tot;
ll num[M];
struct FHQ_Treap{int l,r,size;ll v,mkadd,mkcv,sum,key;bool to_rev;}tr[M];
inline int newnode(ll val)
{
	int id=++tot;
	tr[id].l=tr[id].r=0;
	tr[id].v=tr[id].sum=val;
	tr[id].key=dg();
	tr[id].size=1;
	tr[id].mkcv=-1;
	tr[id].mkadd=0;
	return id;
}
inline void combine(int rt){tr[rt].size=tr[tr[rt].l].size+tr[tr[rt].r].size+1;tr[rt].sum=(tr[tr[rt].l].sum+tr[tr[rt].r].sum+tr[rt].v)%mod;return;}
inline int clone(int rt)
{
	int id=newnode(0);
	tr[id]=tr[rt];
	return id;
}
inline void pushdown_rev(int rt)
{
    swap(tr[rt].l,tr[rt].r);
    tr[rt].to_rev^=1;
    return;
}
inline void pushdown_add(int rt,ll v)
{
    tr[rt].v=(tr[rt].v+v)%mod;
    tr[rt].mkadd=(tr[rt].mkadd+v)%mod;
    tr[rt].sum=(tr[rt].sum+tr[rt].size*v)%mod;
    return;
}
inline void pushdown_cv(int rt,ll v)
{
    tr[rt].mkadd=0;
    tr[rt].mkcv=tr[rt].v=v;
    tr[rt].sum=tr[rt].size*v%mod;
    return;
}
inline void pushdown(int rt)
{
	if(tr[rt].mkcv==-1&&!tr[rt].mkadd&&!tr[rt].to_rev)return;
    if(tr[rt].l)tr[rt].l=clone(tr[rt].l);
	if(tr[rt].r)tr[rt].r=clone(tr[rt].r);
    if(~tr[rt].mkcv)
	{
        if(tr[rt].l)pushdown_cv(tr[rt].l,tr[rt].mkcv);
        if(tr[rt].r)pushdown_cv(tr[rt].r,tr[rt].mkcv);
        tr[rt].mkcv=-1;
    }
    if(tr[rt].mkadd)
	{
        if(tr[rt].l)pushdown_add(tr[rt].l,tr[rt].mkadd);
        if(tr[rt].r)pushdown_add(tr[rt].r,tr[rt].mkadd);
        tr[rt].mkadd=0;
    }
    if(tr[rt].to_rev)
    {
    	if(tr[rt].l)pushdown_rev(tr[rt].l);
	    if(tr[rt].r)pushdown_rev(tr[rt].r);
	    tr[rt].to_rev=0;
	}
	return;
}
inline void split(int rt,ll val,int&l,int&r)
{
	if(!rt){l=0,r=0;return;}
	pushdown(rt);
	if(tr[tr[rt].l].size<val)
	{
		l=clone(rt);
		split(tr[l].r,val-tr[tr[rt].l].size-1,tr[l].r,r);
		combine(l);
	}
	else
	{
		r=clone(rt);
		split(tr[r].l,val,l,tr[r].l);
		combine(r);
	}
	return;
}
inline int merge(int l,int r)
{
	if(!l||!r)return l+r;
	if(tr[l].key<tr[r].key)
	{
		pushdown(l);
		l=clone(l);
		tr[l].r=merge(tr[l].r,r);
		combine(l);
		return l;
	}
	else
	{
		pushdown(r);
		r=clone(r);
		tr[r].l=merge(l,tr[r].l);
		combine(r);
		return r;
	}
}
inline void cover(int l,int r,int val)
{
	int x,y,z;
	split(root,r,x,z);
    split(x,l-1,x,y);
    y=clone(y);
    pushdown_cv(y,val);
    root=merge(merge(x,y),z);
    return;
}
inline void add(int l,int r,int val)
{
	int x,y,z;
	split(root,r,x,z);
    split(x,l-1,x,y);
    y=clone(y);
    pushdown_add(y,val);
    root=merge(merge(x,y),z);
    return;
}
inline void reverse(int l,int r)
{
	int x,y,z;
	split(root,r,x,z);
    split(x,l-1,x,y);
    y=clone(y);
    pushdown_rev(y);
    root=merge(merge(x,y),z);
    return;
}
inline void lrcover(int l1,int r1,int l2,int r2)
{
	int a,b,c,d,e;
	bool fg=0;
	if(l1>l2)swap(l1,l2),swap(r1,r2),fg=1;
	split(root,l1-1,a,b);
    split(b,r1-l1+1,b,c);
    split(c,l2-r1-1,c,d);
    split(d,r2-l2+1,d,e);
    if(fg)b=clone(d);
    else d=clone(b);
    root=merge(merge(merge(merge(a,b),c),d),e);
    return;
}
inline void lrswap(int l1,int r1,int l2,int r2)
{
	int a,b,c,d,e;
	if(l1>l2)swap(l1,l2),swap(r1,r2);
	split(root,l1-1,a,b);
    split(b,r1-l1+1,b,c);
    split(c,l2-r1-1,c,d);
    split(d,r2-l2+1,d,e);
    root=merge(merge(merge(merge(a,d),c),b),e);
    return;
}
inline ll query(int l,int r)
{
	int x,y,z;
	split(root,r,x,z);
    split(x,l-1,x,y);
    ll res=tr[y].sum;
    root=merge(merge(x,y),z);
    return res;
}
inline int build(int l,int r)
{
	if(l>r)return 0;
	int mid=l+r>>1;
	int rt=newnode(num[mid]);	
	tr[rt].l=build(l,mid-1);
	tr[rt].r=build(mid+1,r);
	combine(rt);
	return rt;
}
inline void getnum(int rt)
{
	pushdown(rt);
    if(tr[rt].l)getnum(tr[rt].l);
    num[++n]=tr[rt].v;
    if(tr[rt].r)getnum(tr[rt].r);
    return;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i)num[i]=read();
	root=build(1,n);
	for(int i=1;i<=m;++i)
	{
		int op=read();
		switch(op)
		{
			case 1:{int l=read(),r=read();write(query(l,r)%mod),puts("");break;}
			case 2:{int l=read(),r=read();ll val=read();cover(l,r,val);break;}
			case 3:{int l=read(),r=read();ll val=read();add(l,r,val);break;}
			case 4:{int l1=read(),r1=read(),l2=read(),r2=read();lrcover(l1,r1,l2,r2);break;}
			case 5:{int l1=read(),r1=read(),l2=read(),r2=read();lrswap(l1,r1,l2,r2);break;}
			case 6:{int l=read(),r=read();reverse(l,r);break;}
			default:break;
		}
		if(tot>1500000)
		{
			n=0;
			getnum(root);
			root=tot=0;
			root=build(1,n);
		}
	}
	n=0;
	getnum(root);
	for(int i=1;i<=n;++i)write(num[i]),putchar(' ');
	return 0;
}
