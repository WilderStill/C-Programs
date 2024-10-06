#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
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
struct nodep
{
	int val,id;
	bool operator <(nodep b)
	{
		return val^b.val?val<b.val:id<b.id;
	}
}num[100010];
int tot=0,root=0;
struct node
{
	int size,key,l,r,minn,val,tag;
}tr[200010];
inline int newnode(int v)
{
	tr[++tot].size=1;
	tr[tot].val=tr[tot].minn=v;
	tr[tot].l=tr[tot].r=0;
	tr[tot].key=rand();
	return tot;
}
inline void update(int rt)
{
	tr[rt].size=tr[tr[rt].l].size+tr[tr[rt].r].size+1;
	tr[rt].minn=tr[rt].val;
	if(tr[rt].l)tr[rt].minn=min(tr[rt].minn,tr[tr[rt].l].minn);
	if(tr[rt].r)tr[rt].minn=min(tr[rt].minn,tr[tr[rt].r].minn);
}
inline void pushdown(int rt)
{
	if(tr[rt].tag)
	{
		swap(tr[rt].l,tr[rt].r);
		if(tr[rt].l)tr[tr[rt].l].tag^=1;
		if(tr[rt].r)tr[tr[rt].r].tag^=1;
		tr[rt].tag=0;
	}
}
inline void split(int rt,int v,int&l,int&r)
{
	if(!rt)
	{
		l=r=0;
		return;
	}
	pushdown(rt);
	if(tr[tr[rt].l].size+1<=v)
	{
		l=rt;
        split(tr[rt].r,v-tr[tr[rt].l].size-1,tr[rt].r,r);
    }
    else
	{
		r=rt;
        split(tr[rt].l,v,l,tr[rt].l);
    }
    update(rt);
}
inline int merge(int l,int r)
{
	if(!l||!r)return l+r;
	if(tr[l].key>=tr[r].key)
	{
		pushdown(r);
        tr[r].l=merge(l,tr[r].l);
        update(r);
        return r;
    }
    else
	{
		pushdown(l);
        tr[l].r=merge(tr[l].r,r);
        update(l);
        return l;
    }
}
inline void insert(int v)
{
	root=merge(root,newnode(v));
}
inline void destroy(int v)
{
	int x,y,z;
    split(root,v,y,z);
    split(y,v-1,x,y);
    root=merge(x,z);
}
inline int qrk(int rt,int val)
{
	pushdown(rt);
	if(tr[rt].l&&tr[tr[rt].l].minn==val)return qrk(tr[rt].l,val);
	if(tr[rt].val==val)return tr[tr[rt].l].size+1;
	return qrk(tr[rt].r,val)+tr[tr[rt].l].size+1;
}
int syh[100010];
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)num[i]={read(),i};
	sort(num+1,num+n+1);
	for(int i=1;i<=n;++i)syh[num[i].id]=i;
	for(int i=1;i<=n;++i)insert(syh[i]);
	for(int i=1;i<=n;++i)
	{
		int rk=qrk(root,tr[root].minn),x,y;
		write(rk+i-1),putchar(' ');
		destroy(rk);
		split(root,--rk,x,y);
		tr[x].tag^=1;
		root=merge(x,y);
	}
    return 0;
}
