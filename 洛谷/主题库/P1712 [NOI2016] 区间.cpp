#include<bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define INF 0x3f3f3f3f
#define M 500010
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
int n,m,ans=INF,p[M<<1];
struct interval
{
	int l,r;
	bool operator<(interval b){return (r-l)<(b.r-b.l);}
}syh[M];
struct node
{
	int maxn,tag;
}tr[M<<4];
inline void update(int rt)
{
	tr[rt].maxn=max(tr[lson].maxn,tr[rson].maxn)+tr[rt].tag;
}
inline void modify(int rt,int l,int r,int posl,int posr,int val)
{
    if(l==posl&&r==posr)
    {
        tr[rt].maxn+=val;
        tr[rt].tag+=val;
        return;
    }
    int mid=(l+r)>>1;
    if(posl<=mid)modify(lson,l,mid,posl,min(mid,posr),val);
    if(posr>mid)modify(rson,mid+1,r,max(mid+1,posl),posr,val);
    update(rt);
}
int main()
{
	n=read(),m=read();
    for(int i=1;i<=n;++i)
        p[(i<<1)-1]=syh[i].l=read(),p[i<<1]=syh[i].r=read();
    int len=n<<1;
	sort(p+1,p+len+1);
	len=unique(p+1,p+len+1)-p-1;
    sort(syh+1,syh+n+1);
    for(int i=1;i<=n;++i)
        syh[i].l=lower_bound(p+1,p+len+1,syh[i].l)-p,syh[i].r=lower_bound(p+1,p+len+1,syh[i].r)-p;
    int l=1,r=0;
    while(l<=n)
    {
		while(r<n&&tr[1].maxn<m)++r,modify(1,1,len,syh[r].l,syh[r].r,1);
		if(r==n&&tr[1].maxn<m)break;
		ans=min(ans,p[syh[r].r]-p[syh[r].l]-p[syh[l].r]+p[syh[l].l]);
		modify(1,1,len,syh[l].l,syh[l].r,-1);++l;
	}
    write(ans==INF?-1:ans);
    return 0;
}
