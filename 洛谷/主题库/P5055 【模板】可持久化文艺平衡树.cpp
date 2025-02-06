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
constexpr int M=1.8e7;
mt19937_64 dg(time(0));
int root[M],tot;ll lst;
struct FHQ_Treap{int l,r,size;ll v,sum,key;bool to_rev;}tr[M];
inline int newnode(ll val){int id=++tot;tr[id].l=tr[id].r=0,tr[id].v=tr[id].sum=val,tr[id].key=dg(),tr[id].size=1;return id;}
inline void combine(int rt){tr[rt].size=tr[tr[rt].l].size+tr[tr[rt].r].size+1;tr[rt].sum=tr[tr[rt].l].sum+tr[tr[rt].r].sum+tr[rt].v;return;}
inline int clone(int rt)
{
	int id=newnode(0);
	tr[id]=tr[rt];
	return id;
}
inline void pushdown(int rt)
{
	if(!tr[rt].to_rev)return;
	if(tr[rt].l)tr[rt].l=clone(tr[rt].l);
	if(tr[rt].r)tr[rt].r=clone(tr[rt].r);
	swap(tr[rt].l,tr[rt].r);
	if(tr[rt].l)tr[tr[rt].l].to_rev^=1;
	if(tr[rt].r)tr[tr[rt].r].to_rev^=1;
	tr[rt].to_rev=0;
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
	pushdown(l),pushdown(r);
	if(tr[l].key<tr[r].key)
	{
		tr[l].r=merge(tr[l].r,r);
		combine(l);
		return l;
	}
	else
	{
		tr[r].l=merge(l,tr[r].l);
		combine(r);
		return r;
	}
}
inline void insert(int v,int pos,ll val)
{
	int x,y;
	split(root[v],pos,x,y);
	root[v]=merge(merge(x,newnode(val)),y);
	return;
}
inline void remove(int v,int pos)
{
	int x,y,z;
	split(root[v],pos,x,z);
    split(x,pos-1,x,y);
    root[v]=merge(x,z);
    return;
}
inline void reverse(int v,int l,int r)
{
	int x,y,z;
	split(root[v],r,x,z);
    split(x,l-1,x,y);
    tr[y].to_rev^=1;
    root[v]=merge(merge(x,y),z);
    return;
}
inline ll query(int v,int l,int r)
{
	int x,y,z;
	split(root[v],r,x,z);
    split(x,l-1,x,y);
    ll res=tr[y].sum;
    root[v]=merge(merge(x,y),z);
    return res;
}
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)
	{
		int v=read(),op=read();
		root[i]=root[v];
		switch(op)
		{
			case 1:{int pos=read()^lst;ll val=read()^lst;insert(i,pos,val);break;}
			case 2:{int pos=read()^lst;remove(i,pos);break;}
			case 3:{int l=read()^lst,r=read()^lst;reverse(i,l,r);break;}
			case 4:{int l=read()^lst,r=read()^lst;write(lst=query(i,l,r)),puts("");break;}
			default:break;
		}
	}
	return 0;
}
