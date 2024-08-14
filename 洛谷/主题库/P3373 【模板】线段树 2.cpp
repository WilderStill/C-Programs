#include<bits/stdc++.h>
#define M 1145141
#define ll long long
using namespace std;
ll b[M];
int p=571373;
struct node
{
    ll v,mul,add;
}tr[4*M];
void build(int rt,int l,int r)
{
	int mid=(l+r)/2;
    tr[rt].mul=1;
    tr[rt].add=0;
    if(l==r)
        tr[rt].v=b[l];
    else
	{
        build(rt*2,l,mid);
        build(rt*2+1,mid+1,r);
        tr[rt].v=tr[rt*2].v+tr[rt*2+1].v;
    }
    tr[rt].v%=p;
    return ;
}
void pushdown(int rt,int l,int r)
{
	int mid=(l+r)/2;
    tr[rt*2].v=(tr[rt*2].v*tr[rt].mul+tr[rt].add*(mid-l+1))%p;
    tr[rt*2+1].v=(tr[rt*2+1].v*tr[rt].mul+tr[rt].add*(r-mid))%p;
    tr[rt*2].mul=(tr[rt*2].mul*tr[rt].mul)%p;
    tr[rt*2+1].mul=(tr[rt*2+1].mul*tr[rt].mul)%p;
    tr[rt*2].add=(tr[rt*2].add*tr[rt].mul+tr[rt].add)%p;
    tr[rt*2+1].add=(tr[rt*2+1].add*tr[rt].mul+tr[rt].add)%p;
    tr[rt].mul=1;
    tr[rt].add=0;
    return ;
}
void update1(int rt,int posl,int posr,int l,int r,ll k)
{
	int mid=(posl+posr)/2;
    if(r<posl || posr<l) return;
    if(l<=posl && posr<=r)
	{
        tr[rt].v=(tr[rt].v*k)%p;
        tr[rt].mul=(tr[rt].mul*k)%p;
        tr[rt].add=(tr[rt].add*k)%p;
        return ;
    }
    pushdown(rt,posl,posr);
    update1(rt*2,posl,mid,l,r,k);
    update1(rt*2+1,mid+1,posr,l,r,k);
    tr[rt].v=(tr[rt*2].v+tr[rt*2+1].v)%p;
    return ;
}
void update2(int rt,int posl,int posr,int l,int r,ll k)
{
	int mid=(posl+posr)/2;
    if(r<posl||posr<l) return ;
    if(l<=posl && posr<=r)
	{
        tr[rt].add=(tr[rt].add+k)%p;
        tr[rt].v=(tr[rt].v+k*(posr-posl+1))%p;
        return ;
    }
    pushdown(rt, posl, posr);
    update2(rt*2,posl,mid,l,r,k);
    update2(rt*2+1,mid+1,posr,l,r,k);
    tr[rt].v=(tr[rt*2].v+tr[rt*2+1].v)%p;
    return ;
}
ll query(int rt,int posl,int posr,int l,int r)
{
	int mid=(posl+posr)/2;
    if(r<posl||posr<l) return 0;
    if(l<=posl&&posr<=r) return tr[rt].v;
    pushdown(rt,posl,posr);
    return (query(rt*2,posl,mid,l,r)+query(rt*2+1,mid+1,posr,l,r))%p;
}
int main()
{
    int n,m;
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
    build(1,1,n);
    for(int i=1,op,x,y;i<=m;i++)
	{
        scanf("%d",&op);
        ll k;
        switch(op)
        {
        	case 1:
			{
	            scanf("%d%d%lld",&x,&y,&k);
	            update1(1,1,n,x,y,k);
	            break;
	        }
	        case 2:
			{
	            scanf("%d%d%lld",&x,&y,&k);
	            update2(1,1,n,x,y,k);
	            break;
	        }
	        case 3:
			{
	            scanf("%d%d",&x,&y);
	            printf("%lld\n",query(1,1,n,x,y));
	        }
		}
    }
    return 0;
}
