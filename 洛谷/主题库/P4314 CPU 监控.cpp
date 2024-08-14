#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define M 100010
#define lson (rt<<1)
#define rson ((rt<<1)|1)
using namespace std;
inline int read()
{
    int x=0,f=1;
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
inline void write(int x)
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
int n,m,v[M];
struct node
{
	int val,l,r,add,maxn,maxnh,valh,addh;
	bool tag;
	void change(int x,int xh)
	{
		if(tag)valh=max(valh,xh);
		else tag=1,valh=xh;
		maxnh=max(maxnh,xh);
		val=maxn=x;
		add=0;
	}
	void add_(int x,int xh)
	{
		addh=max(addh,add+xh);
		maxnh=max(maxnh,maxn+xh);
		add+=x,maxn+=x;
	}
	void update(int x,int xh)
	{
		if(tag)change(val+x,val+xh);
		else add_(x,xh);
	}
}t[M<<2];
void update(int rt)
{
	t[rt].maxn=max(t[lson].maxn,t[rson].maxn);
	t[rt].maxnh=max(t[rt].maxnh,t[rt].maxn);
}
void build(int rt,int l,int r)
{
	t[rt].l=l;t[rt].r=r;
	t[rt].add=t[rt].val=t[rt].addh=t[rt].valh=0;
	t[rt].maxn=t[rt].maxnh=-INF;
	t[rt].tag=0;
	if(l==r)
	{
		t[rt].maxn=t[rt].maxnh=v[l];
		return;
	}
	int mid=(l+r)>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	update(rt);
}
void pushdown(int rt)
{
	t[lson].update(t[rt].add,t[rt].addh);
	t[rson].update(t[rt].add,t[rt].addh);
	t[rt].add=t[rt].addh=0;
	if(t[rt].tag)
	{
		t[lson].change(t[rt].val,t[rt].valh);
		t[rson].change(t[rt].val,t[rt].valh);
		t[rt].tag=t[rt].val=t[rt].valh=0;
	}
}
int query_max(int rt,int l,int r)
{
	if(t[rt].l>=l&&t[rt].r<=r)return t[rt].maxn;
	pushdown(rt);
	int res=-INF,mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)res=max(res,query_max(lson,l,r));
	if(r>mid)res=max(res,query_max(rson,l,r));
	return res;
}
int query_maxh(int rt,int l,int r)
{
	if(t[rt].l>=l&&t[rt].r<=r)return t[rt].maxnh;
	pushdown(rt);
	int res=-INF,mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)res=max(res,query_maxh(lson,l,r));
	if(r>mid)res=max(res,query_maxh(rson,l,r));
	return res;
}
void add(int rt,int l,int r,int x)
{
	if(t[rt].l>=l&&t[rt].r<=r){t[rt].update(x,x);return;}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)add(lson,l,r,x);
	if(r>mid)add(rson,l,r,x);
	update(rt);
}
void change(int rt,int l,int r,int x)
{
	if(t[rt].l>=l&&t[rt].r<=r){t[rt].change(x,x);return;}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)change(lson,l,r,x);
	if(r>mid)change(rson,l,r,x);
	update(rt);
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)v[i]=read();
	build(1,1,n);
	m=read();
	for(int i=1,l,r,x;i<=m;++i)
	{
		char op[5];
		scanf("%s",op);
		l=read(),r=read();
		if(op[0]=='P'){x=read();add(1,l,r,x);}
        else if(op[0]=='C'){x=read();change(1,l,r,x);}
        else if(op[0]=='Q')write(query_max(1,l,r)),puts("");
        else write(query_maxh(1,l,r)),puts("");
	}
	return 0;
}
