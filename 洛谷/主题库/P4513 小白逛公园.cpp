#include<bits/stdc++.h>
#define ll long long
#define M 500010
#define INF 0x3f3f3f3f
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
	return x*f;
}
inline void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
	return;
}
inline void write(ll x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
	return;
}
int n,m,top,num[M],tot,rt;
struct node
{
	int key,size,to_ms,ls,rs,val;
	ll max,s,l,r;
}tr[M];
inline void pushup(int rt)
{
	tr[rt].size=tr[tr[rt].ls].size+tr[tr[rt].rs].size+1;
	tr[rt].s=tr[tr[rt].ls].s+tr[tr[rt].rs].s+tr[rt].val;
	tr[rt].l=max(tr[tr[rt].ls].l,max(0ll,tr[tr[rt].ls].s+tr[rt].val+tr[tr[rt].rs].l));
	tr[rt].r=max(tr[tr[rt].rs].r,max(0ll,tr[tr[rt].rs].s+tr[rt].val+tr[tr[rt].ls].r));
	tr[rt].max=max((ll)tr[rt].val,tr[tr[rt].ls].r+tr[rt].val+tr[tr[rt].rs].l);
	if(tr[rt].ls)tr[rt].max=max(tr[rt].max,tr[tr[rt].ls].max);
	if(tr[rt].rs)tr[rt].max=max(tr[rt].max,tr[tr[rt].rs].max);
}
inline void pushdown(int rt)
{
	if(tr[rt].to_ms!=INF)
	{
		int val=tr[rt].to_ms;
		if(tr[rt].ls)
		{
			tr[tr[rt].ls].to_ms=tr[tr[rt].ls].val=val;
			tr[tr[rt].ls].s=tr[tr[rt].ls].size*val;
			tr[tr[rt].ls].l=tr[tr[rt].ls].r=max(0ll,tr[tr[rt].ls].s);
			tr[tr[rt].ls].max=max((ll)val,tr[tr[rt].ls].s);
		}
		if(tr[rt].rs)
		{
			tr[tr[rt].rs].to_ms=tr[tr[rt].rs].val=val;
			tr[tr[rt].rs].s=tr[tr[rt].rs].size*val;
			tr[tr[rt].rs].l=tr[tr[rt].rs].r=max(0ll,tr[tr[rt].rs].s);
			tr[tr[rt].rs].max=max((ll)val,tr[tr[rt].rs].s);
		}
		tr[rt].to_ms=INF;
	}
}
inline void split(int rt,int size,int &x,int &y)
{
	if(!rt)
	{
		x=y=0;
		return;
	}
	pushdown(rt);
	if(size<=tr[tr[rt].ls].size)
	{
		y=rt;
		split(tr[y].ls,size,x,tr[y].ls);
		pushup(y);
	}
	else
	{
		x=rt;
		split(tr[x].rs,size-tr[tr[x].ls].size-1,tr[x].rs,y);
		pushup(x);
	}
	pushup(rt);
}
inline int merge(int x,int y)
{
	if(!x||!y)return x+y;
	if(tr[x].key<tr[y].key)
	{
		pushdown(x);
		tr[x].rs=merge(tr[x].rs,y);
		pushup(x);
		return x;
	}
	else
	{
		pushdown(y);
		tr[y].ls=merge(x,tr[y].ls);
		pushup(y);
		return y;
	}
}
inline int newnode(int val)
{
	tr[++tot].key=rand();
	tr[tot].to_ms=INF;
	tr[tot].ls=0;
	tr[tot].rs=0;
	tr[tot].max=tr[tot].s=tr[tot].val=val;
	tr[tot].l=tr[tot].r=max(val,0);
	tr[tot].size=1;
	return tot;
}
inline int build(int l,int r)
{
	if(l==r)return newnode(num[l]);
	int mid=l+r>>1;
	int pl=build(l,mid),pr=build(mid+1,r);
	return merge(pl,pr);
}
inline void modify(int pos,int val)
{
	int x,y,z;
	split(rt,pos,x,z);
	split(x,pos-1,x,y);
	tr[y].to_ms=tr[y].val=val;
	tr[y].s=tr[y].size*val;
	tr[y].l=tr[y].r=max(0ll,tr[y].s);
	tr[y].max=max((ll)val,tr[y].s);
	rt=merge(merge(x,y),z);
}
inline void query(int l,int r)
{
	int x,y,z;
	split(rt,r,x,z);
	split(x,l-1,x,y);
	write(tr[y].max);
	puts("");
	rt=merge(merge(x,y),z);
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i)num[i]=read();
	rt=build(1,n);
	for(int i=1;i<=m;++i)
	{
		int op=read();
		if(op==1)
		{
			int a=read(),b=read();
			if(a>b)a^=b^=a^=b;
			query(a,b);
		}
		if(op==2)
		{
			int s=read(),p=read();
			modify(s,p);
		}
	}
	return 0;
}
