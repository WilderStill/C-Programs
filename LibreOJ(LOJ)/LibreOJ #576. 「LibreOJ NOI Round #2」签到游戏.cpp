#include<bits/stdc++.h>
#define int long long
#define lson rt<<1
#define rson rt<<1|1
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
int n,q,a[100010];
int tr[400010];
void build(int rt,int l,int r)
{
	if(l==r)
	{
		tr[rt]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	tr[rt]=__gcd(tr[lson],tr[rson]);
}
void update(int rt,int l,int r,int pos,int v)
{
	if(l==r)
	{
		tr[rt]=v;
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid)update(lson,l,mid,pos,v);
	else update(rson,mid+1,r,pos,v);
	tr[rt]=__gcd(tr[lson],tr[rson]);
}
int findrt(int rt,int l,int r,int nowl,int nowr)
{
	if(l==r)return l;
	int mid=(l+r)>>1;
	int x=__gcd(tr[lson],nowl);
	int y=__gcd(tr[rson],nowr);
	if(x<=y)return findrt(lson,l,mid,nowl,y);
	else return findrt(rson,mid+1,r,x,nowr);
}
int query_l(int rt,int l,int r,int pos,int nowr)
{
	if(l==r)return __gcd(tr[rt],nowr);
	int mid=(l+r)>>1;
	int x=__gcd(tr[rt],nowr);
	int y=__gcd(tr[rson],nowr);
	if(pos<=mid)return query_l(lson,l,mid,pos,y);
	else return (x==y?(mid-l+1)*x:query_l(lson,l,mid,mid,y))+query_l(rson,mid+1,r,pos,nowr);
}
int query_r(int rt,int l,int r,int pos,int nowl)
{
	if(l==r)return __gcd(tr[rt],nowl);
	int mid=(l+r)>>1;
	int x=__gcd(tr[lson],nowl);
	int y=__gcd(tr[rt],nowl);
	if(pos>mid)return query_r(rson,mid+1,r,pos,x);
	else return (x==y?(r-mid)*y:query_r(rson,mid+1,r,mid+1,x))+query_r(lson,l,mid,pos,nowl);
}
signed main()
{
	n=read(),q=read();
	for(int i=1;i<=n;++i)a[i]=read();
	build(1,1,n);
	for(int i=1;i<=q;++i)
	{
		int k=read(),s=read();
		update(1,1,n,k,s);
		int rt=findrt(1,1,n,0,0);
		write(query_l(1,1,n,rt,0)+query_r(1,1,n,rt,0)-tr[1]);
		puts("");
	}
	return 0;
}
