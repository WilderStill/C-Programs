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
int rt,tot;
struct node
{
    int size,key,l,r;
}tr[7000100];
void combine(int rt)
{
    tr[rt].size=tr[tr[rt].l].size+tr[tr[rt].r].size+1;
}
inline int newnode()
{
	tr[++tot].key=rand();
	tr[tot].l=tr[tot].r=0;
	tr[tot].size=1;
    return tot;
}
inline void split(int rt,int val,int &l,int &r)
{
    if(!rt)
	{
        l=r=0;return;
    }
    if(tr[tr[rt].l].size<val)
	{
        l=rt;
        split(tr[rt].r,val-tr[tr[rt].l].size-1,tr[rt].r,r);
    }
    else
	{
        r=rt;
        split(tr[rt].l,val,l,tr[rt].l);
    }
    combine(rt);
}
inline int merge(int l,int r)
{
    if(!l||!r)return l+r;
    if(tr[l].key<=tr[r].key)
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
int n,l,r,rs;
int main()
{
	rs=n=read();
	for(int i=1;i<=n;++i)rt=merge(rt,newnode());
	for(int i=1;i<=n;++i)
	{
		int pos=read()%rs;--rs;
		if(pos)
		{
			split(rt,pos,l,r);
			rt=merge(r,l);
		}
		split(rt,1,l,r);
		write(l),puts("");
		rt=r;
	}
	return 0;
}

