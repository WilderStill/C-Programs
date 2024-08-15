#include<bits/stdc++.h>
#define ll long long
#define M 1145141
using namespace std;
ll n,m,t,nl=1,nr,block,lastblo,ans;
ll num[M],val[M],tmp[M],cnt[M],vis[M],blo[M],l[M],r[M];
struct node
{
	ll l,r,id,res;
}q[M];
bool cmp1(node x,node y){return x.id<y.id;}
bool cmp2(node x,node y)
{
	if(blo[x.l]!=blo[y.l])return blo[x.l]<blo[y.l];
	return x.r<y.r;
}
ll add(ll x,ll maxn)
{
	cnt[num[x]]++;
	maxn=max(maxn,cnt[num[x]]*val[x]);
	return maxn;
}
void resume(ll x)
{
	cnt[num[x]]--;
	return;
}
void build()
{
	ll kb=n/block;
    for(int i=1;i<=kb;i++)
    {
        if(i*block>n)break;
        l[i]=(i-1)*block+1;r[i]=i*block;
    }
    if(r[kb]<n)kb++,l[kb]=r[kb-1]+1,r[kb]=n;
    for(int i=1;i<=kb;i++)
        for(int j=l[i];j<=r[i];j++)blo[j]=i;
    return;
}
int main()
{
	scanf("%lld%lld",&n,&m);t=n;
	block=sqrt(n);
	for(ll i=1;i<=n;i++){scanf("%lld",&val[i]);tmp[i]=val[i];}
	sort(tmp+1,tmp+t+1);
    t=unique(tmp+1,tmp+t+1)-(tmp+1);
    for(ll i=1;i<=n;i++)num[i]=lower_bound(tmp+1,tmp+t+1,val[i])-tmp;
	build();
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&q[i].l,&q[i].r);
		q[i].id=i;
	}
	sort(q+1,q+1+m,cmp2);
	lastblo=0;
	for(ll i=1;i<=m;i++)
	{
		if(blo[q[i].l]==blo[q[i].r])
		{
			ll tmpans=0;
			for(int j=q[i].l;j<=q[i].r;j++)vis[num[j]]++;
	        for(int j=q[i].l;j<=q[i].r;j++)tmpans=max(tmpans,vis[num[j]]*val[j]);
	        for(int j=q[i].l;j<=q[i].r;j++)vis[num[j]]--;
	        q[i].res=tmpans;
		}
		else
		{
			if(lastblo!=blo[q[i].l])
		    {
		        while(nr>r[blo[q[i].l]])resume(nr--);
		        while(nl<r[blo[q[i].l]]+1)resume(nl++);
		        ans=0,lastblo=blo[q[i].l];
		    }
			while(nr<q[i].r)ans=add(++nr,ans);
		    ll tmpans=ans,tl=nl;
		    while(tl>q[i].l)tmpans=add(--tl,tmpans);
		    while(tl<nl)resume(tl++);
			q[i].res=tmpans;
		}
	}
	sort(q+1,q+1+m,cmp1);
	for(int i=1;i<=m;i++)printf("%lld\n",q[i].res);
	return 0;
}
