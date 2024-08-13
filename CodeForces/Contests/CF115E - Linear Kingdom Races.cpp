#include<bits/stdc++.h>
#define M 200010
#define ll long long
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;
struct gnode
{
	int to,nxt;
	ll val;
}edge[M];
struct tnode
{
	ll maxn,tag;
}tr[M<<2];
int hd[M],tot;
ll v[M];
void addedge(int u,int v,ll w)
{
	edge[++tot].nxt=hd[u];
	edge[tot].to=v;
	edge[tot].val=w;
	hd[u]=tot;
}
void pushdown(int rt)
{
	if(tr[rt].tag)
	{
		tr[lson].maxn+=tr[rt].tag;
		tr[rson].maxn+=tr[rt].tag;
		tr[lson].tag+=tr[rt].tag;
		tr[rson].tag+=tr[rt].tag;
		tr[rt].tag=0;
	}
}
void pushup(int rt)
{
    tr[rt].maxn=max(tr[lson].maxn,tr[rson].maxn);
}
void modify_add(int rt,int l,int r,int posl,int posr,ll val)
{
    if(posl<=l&&r<=posr)
	{
		tr[rt].maxn+=val;
		tr[rt].tag+=val;
        return;
    }
    pushdown(rt);
    int mid=(l+r)>>1;
    if(posl<=mid)modify_add(lson,l,mid,posl,posr,val);
    if(posr>mid)modify_add(rson,mid+1,r,posl,posr,val);
    pushup(rt);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%lld",&v[i]);
    for(int i=1,u,v;i<=m;++i)
	{
        ll w;
        scanf("%d%d%lld",&u,&v,&w);
        addedge(v,u,w);
    }
    ll ans=0;
    for(int i=1;i<=n;++i)
	{
        modify_add(1,1,n,i,i,ans);
        modify_add(1,1,n,1,i,-v[i]);
        for(int j=hd[i];j;j=edge[j].nxt)
            modify_add(1,1,n,1,edge[j].to,edge[j].val);
        ans=max(ans,tr[1].maxn);
    }
    printf("%lld",ans);
    return 0;
}
