#include<bits/stdc++.h>
#define ll long long
#define M 1145141
using namespace std;
ll n,m,nl=1,nr,block,lastblo,ans,tmp;
ll num[M],cnt[M],vis[M],blo[M],l[M],r[M];
struct node
{
	ll l,r,id,res;
}q[M];
bool cmp1(node x,node y){return x.id<y.id;}
bool cmp2(node x,node y)
{
	if(blo[x.l]!=blo[y.l])return blo[x.l]<blo[y.l];
	return x.r>y.r;
}
void init()
{
	for(int i=1;i<=n;i++)if(num[i]<=n+1)vis[num[i]]++;
    while(vis[tmp])tmp++;
}
void remove(ll x,ll &minn)
{
	if(num[x]>n+1)return ;
	vis[num[x]]--;
	if(!vis[num[x]])minn=min(minn,num[x]);
}
void resume(ll x){if(num[x]<=n+1)vis[num[x]]++;}
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
	scanf("%lld%lld",&n,&m);
	block=sqrt(n);
	for(ll i=1;i<=n;i++){scanf("%lld",&num[i]);}
	build();
	init();
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&q[i].l,&q[i].r);
		q[i].id=i;
	}
	sort(q+1,q+1+m,cmp2);
	lastblo=0,nr=n;
	for(ll i=1;i<=m;i++)
	{
		if(blo[q[i].l]==blo[q[i].r])
		{
			ll tmpans=0;
			for(int j=q[i].l;j<=q[i].r;j++)if(num[j]<=n+1)cnt[num[j]]++;
            while(cnt[tmpans])tmpans++;
	        for(int j=q[i].l;j<=q[i].r;j++)if(num[j]<=n+1)cnt[num[j]]--;
	        q[i].res=tmpans;                                                                                                                                                                                                    
		}
		else
		{
			if(lastblo!=blo[q[i].l])
		    {
		        while(nr<n)resume(++nr);
		        while(nl<l[blo[q[i].l]])remove(nl++,tmp);
		        ans=tmp,lastblo=blo[q[i].l];
		    }
			while(nr>q[i].r)remove(nr--,ans);
		    ll tmpans=ans,tl=nl;
	        while(tl<q[i].l)remove(tl++,tmpans);
		    while(tl>nl)resume(--tl);
			q[i].res=tmpans;
		}
	}
	sort(q+1,q+1+m,cmp1);
	for(int i=1;i<=m;i++)printf("%lld\n",q[i].res);
	return 0;
}
