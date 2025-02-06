#include<bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define int long long
using namespace std;
inline int read()
{
	int x=0;
	char ch=getchar();
	while(ch<48|ch>57)ch=getchar();
	while(ch>=48&ch<=57)
	{
		x=(x<<1)+(x<<3)+ch-48;
		ch=getchar();
	}
	return x;
}
inline void write(int x)
{
	if(x>9)write(x/10);
	putchar(x-x/10*10+48);
	return;
}
int lst;
struct node{int sum,rv,mk;}tr[4000004];
inline void pushdown(int rt,int l,int r)
{
	int v=tr[rt].mk;
	tr[rt].mk=0;
    tr[lson].mk=tr[rson].mk=v;
	tr[lson].rv=tr[rson].rv=v;
    int mid=l+r>>1;
    tr[lson].sum=(mid-l+1)*v;
    tr[rson].sum=(r-mid)*v;
    return;
}
inline void pushup(int rt)
{
	tr[rt].sum=tr[lson].sum+tr[rson].sum;
    tr[rt].rv=tr[rson].rv;
    return;
}
inline void modify(int rt,int l,int r,int posl,int posr,int v)
{
    if(posl>r||posr<l)return;
    if(posl<=l&&r<=posr)
	{
		tr[rt]={(r-l+1)*v,v,v};
		return;
	}
    int mid=l+r>>1;
    if(tr[rt].mk)pushdown(rt,l,r);
    modify(lson,l,mid,posl,posr,v);
    modify(rson,mid+1,r,posl,posr,v);
    pushup(rt);
    return;
}
inline int query(int rt,int l,int r,int posl,int posr)
{
    if(posl>r||posr<l)return 0;
    if(posl<=l&&r<=posr)return tr[rt].sum;
    int mid=l+r>>1;
    if(tr[rt].mk)pushdown(rt,l,r);
    return query(lson,l,mid,posl,posr)+query(rson,mid+1,r,posl,posr);
}
inline int find(int rt,int l,int r,int v)
{
    if(l==r)return l;
    if(tr[rt].mk)pushdown(rt,l,r);
    int mid=l+r>>1;
    if(tr[lson].rv>=v)return find(lson,l,mid,v);
    return find(rson,mid+1,r,v);
}
signed main()
{
    int n=read(),q=read();
    for(int i=1;i<=n;++i)modify(1,1,n,i,i,i);
    for(int i=1;i<=q;++i)
    {
        int l=read()^lst,r=read()^lst,id=find(1,1,n,r)-1;
        write(lst=id<l?0:r*(id-l+1)-query(1,1,n,l,id)),puts("");
        if(id>=l)modify(1,1,n,l,id,r);
    }
    return 0;
}
