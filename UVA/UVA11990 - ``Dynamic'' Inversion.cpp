#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) (x&(-x))
#define mid (l+r)/2
using namespace std;
const int N=200010;
const int M=N*443;
int n,m,tot,a[N],pos[N],suma[N],sumb[N],rt[N],t[M],ls[M],rs[M];
ll ans;
inline void change(int &p,int l,int r,int x,int y)
{
    if(!p) p=++tot;
	t[p]+=y;
    if(l==r) return;
    if(x<=mid) change(ls[p],l,mid,x,y);
    else change(rs[p],mid+1,r,x,y);
}
inline int query(int l,int r,int x,int mode)
{
    int cnta=0,cntb=0,res=0;
    for(int i=l-1;i;i-=lowbit(i)) suma[++cnta]=rt[i];
    for(int i=r;i;i-=lowbit(i)) sumb[++cntb]=rt[i];
    l=1,r=n;
    while(l!=r)
	{
        if(x>mid)
		{
            if(mode)
			{
                for(int i=1;i<=cnta;++i) res-=t[ls[suma[i]]];
                for(int i=1;i<=cntb;++i) res+=t[ls[sumb[i]]];
            }
            for(int i=1;i<=cnta;++i) suma[i]=rs[suma[i]];
            for(int i=1;i<=cntb;++i) sumb[i]=rs[sumb[i]];
            l=mid+1;
        }
        else
		{
            if(!mode)
			{
                for(int i=1;i<=cnta;++i) res-=t[rs[suma[i]]];
                for(int i=1;i<=cntb;++i) res+=t[rs[sumb[i]]];
            }
            for(int i=1;i<=cnta;++i) suma[i]=ls[suma[i]];
            for(int i=1;i<=cntb;++i) sumb[i]=ls[sumb[i]];
            r=mid;
        }
    }
    return res;
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(rt,0,sizeof(rt));
		for(int i=0;i<=tot;++i)ls[i]=rs[i]=t[i]=0;
		tot=ans=0;
		for(int i=1;i<=n;++i)
		{
	        scanf("%d",&a[i]);
			pos[a[i]]=i;
	        ans+=query(1,i-1,a[i],0);
	        for(int j=i;j<=n;j+=lowbit(j)) change(rt[j],1,n,a[i],1);
	    }
	    for(int i=1;i<=m;++i)
		{
			printf("%lld\n",ans);
			int x;
	        scanf("%d",&x);
	        ans-=query(1,pos[x]-1,x,0);
	        ans-=query(pos[x]+1,n,x,1);
	        for(int j=pos[x];j<=n;j+=lowbit(j)) change(rt[j],1,n,x,-1);
	    }
	}
    return 0;
}
