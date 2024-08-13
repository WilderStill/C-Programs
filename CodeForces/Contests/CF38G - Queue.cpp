#include<bits/stdc++.h>
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
int a[200010],c[200010];
namespace FHQ_Treap_Array
{
	#define INF 0x3f3f3f3f
	int tot=0,root=0;
	struct node
	{
		int size,key,l,r,val,maxn;
	}tr[200010];
	int newnode(int v)
	{
		tr[++tot].val=v;
		tr[tot].maxn=v;
		tr[tot].l=tr[tot].r=0;
		tr[tot].key=rand()*rand()%INF+1;
		tr[tot].size=1;
		return tot;
	}
	void update(int rt)
	{
		tr[rt].size=tr[tr[rt].l].size+tr[tr[rt].r].size+1;
		tr[rt].maxn=max(tr[tr[rt].l].maxn,max(tr[rt].val,tr[tr[rt].r].maxn));
	}
	void split(int rt,int v,int&l,int&r)
	{
		if(!rt)
		{
			l=r=0;
			return;
		}
		if(tr[tr[rt].l].size<v)
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
	int merge(int l,int r)
	{
		if(!l||!r)return l+r;
		if(tr[l].key<tr[r].key)
		{
	        tr[l].r=merge(tr[l].r,r);
	        update(l);
	        return l;
	    }
	    else
		{
	        tr[r].l=merge(l,tr[r].l);
	        update(r);
	        return r;
	    }
	}
	int query(int rt,int pos)
	{
		if(!rt)return 0;
		if(!tr[rt].l&&!tr[rt].r)return tr[rt].val<a[pos];
		if(tr[tr[rt].r].maxn>=a[pos]||tr[rt].val>=a[pos])return query(tr[rt].r,pos);
		else return query(tr[rt].l,pos)+tr[tr[rt].r].size+1;
	}
	void print(int rt)
	{
		if(tr[rt].l)print(tr[rt].l);
		write(rt),putchar(' ');
		if(tr[rt].r)print(tr[rt].r);
	}
}
using namespace FHQ_Treap_Array;
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		c[i]=read();
		if(i-1<=c[i])
		{
			int x,y;
			split(root,i-query(root,i)-1,x,y);
			root=merge(x,merge(newnode(a[i]),y));
		}
		else
		{
			int x,y,z;
			split(root,i-c[i]-1,x,y);
			split(y,c[i]-query(y,i),y,z);
			root=merge(merge(x,y),merge(newnode(a[i]),z));
		}
    }
    print(root);
	return 0;
}
