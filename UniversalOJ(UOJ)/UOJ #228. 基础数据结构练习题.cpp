#include<bits/stdc++.h>
#define lson (rt<<1)
#define rson ((rt<<1)|1)
#define mid ((l+r)>>1)
#define ll long long
using namespace std;
const ll M=100010;
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
struct node
{
	ll sum,add,maxn,minn;
}tr[M<<2];
int n,m;
ll num[M];
void update(ll rt,ll l,ll r,ll val)
{
	tr[rt].sum+=val*(r-l+1);
	tr[rt].maxn+=val;
	tr[rt].minn+=val;
	tr[rt].add+=val;
}
void pushdown(ll rt,ll l,ll r)
{
	tr[rt].sum=tr[lson].sum+tr[rson].sum+tr[rt].add*(r-l+1);
	tr[rt].maxn=max(tr[lson].maxn,tr[rson].maxn)+tr[rt].add;
    tr[rt].minn=min(tr[lson].minn,tr[rson].minn)+tr[rt].add;
}
void build(ll rt,ll l,ll r)
{
    if(l==r)
	{
	    tr[rt].sum=tr[rt].maxn=tr[rt].minn=num[l];
	    return;
    }
    build(lson,l,mid);
	build(rson,mid+1,r);
    pushdown(rt,l,r);
}
void modify_add(ll rt,ll l,ll r,ll posl,ll posr,ll val)
{
    if(r<posl||posr<l)return;
    if(posl<=l&&r<=posr)
	{
	    update(rt,l,r,val);
	    return;
    }
    modify_add(lson,l,mid,posl,posr,val);
    modify_add(rson,mid+1,r,posl,posr,val);
    pushdown(rt,l,r);
}
void modify_sqrt(ll rt,ll l,ll r,ll posl,ll posr,ll val)
{
    if(r<posl||posr<l)return;
    if(posl<=l&&r<=posr)
	{
	    ll minsqrt=sqrt(tr[rt].minn+val),maxsqrt=sqrt(tr[rt].maxn+val);
	    if((tr[rt].maxn==tr[rt].minn)||(tr[rt].minn+1==tr[rt].maxn&&minsqrt+1==maxsqrt))
		{
	        ll delt=tr[rt].minn+val-(ll)sqrt(tr[rt].minn+val);
	        update(rt,l,r,-delt);
	        return;
	    }
    }
    val+=tr[rt].add;
    modify_sqrt(lson,l,mid,posl,posr,val);
    modify_sqrt(rson,mid+1,r,posl,posr,val);
    pushdown(rt,l,r);
}
ll query(ll rt,ll l,ll r,ll posl,ll posr,ll val)
{
    if(r<posl||posr<l)return 0;
    if(posl<=l&&r<=posr)return tr[rt].sum+val*(r-l+1);
    val+=tr[rt].add;
    return query(lson,l,mid,posl,posr,val)+query(rson,mid+1,r,posl,posr,val);
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;++i)num[i]=read();
    build(1,1,n);
    while(m--)
	{
	    ll op=read(),l=read(),r=read();
	    switch(op)
	    {
	    	case 1:{ll w=read();modify_add(1,1,n,l,r,w);break;}
	    	case 2:{modify_sqrt(1,1,n,l,r,0);break;}
	    	case 3:{write(query(1,1,n,l,r,0));puts("");break;}
		}
    }
    return 0;
}
