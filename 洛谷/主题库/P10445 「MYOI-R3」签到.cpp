#include<bits/stdc++.h>
#define ubn upper_bound
#define bg(v) v.begin()
#define al(v) v.begin(),v.end()
#define INF 0x3f3f3f3f
#define ll long long
#define pll pair<ll,ll>
#define mp(x,y) make_pair(x,y)
#define id first
#define x second
using namespace std;
ll n,m,p,l,pl,r=-1,pr=-1,minl=INF,minr=INF,ans;
bool cmp(pll x,pll y)
{
	if(x.x==y.x)return abs(x.id-p)<abs(y.id-p);
	return x.x<y.x;
}
vector<pll>rgt,lft;
bool fg=0;
int main()
{
	scanf("%lld%lld%lld",&n,&m,&p);
    for(ll i=1,x;i<=n;++i)
	{
        scanf("%lld",&x);
        if(i==p&&x<0)fg=1;
        if(x>=0)rgt.push_back(mp(i,x));
        else lft.push_back(mp(i,-x));
    }
    sort(al(rgt),cmp);
	sort(al(lft),cmp);
    if(fg)swap(rgt,lft);
    for(auto &i:lft)i.x*=2;
    ans=ubn(al(lft),mp(INF,m),cmp)-bg(lft);
	pl=l=ubn(al(lft),mp(INF,m),cmp)-bg(lft)-1;
    for(ll i=0,t,pos,res;i<rgt.size();++i)
	{
        if(rgt[i].x>m+5)break;
        if(rgt[i].id==p)m+=5;
		if(rgt[i].x*2>m+5)break;
        if(rgt[i].x*2>m)continue;
        t=m-rgt[i].x*2;
        pos=ubn(al(lft),mp(INF,t),cmp)-bg(lft)-1;
        res=ubn(al(lft),mp(INF,t),cmp)-bg(lft)+i+1;
        if(res>ans)
		{
            pl=l=pos,pr=r=i;
            minl=minr=INF;
			ans=res;
        }
		else if(res==ans)
		{
            if(pos!=l||i!=r)
			{
                while(pl>pos)minl=min(minl,lft[pl--].id);
                while(pr<i)minr=min(minr,rgt[++pr].id);
                if(minr<minl)
				{
                    pl=l=pos,pr=r=i;
                    minl=minr=INF;
                }
            }
        }
    }
    printf("%lld\n",ans);
    for(ll i=0;i<=r;++i)printf("%lld ",rgt[i].id);
    for(ll i=0;i<=l;++i)printf("%lld ",lft[i].id);
    return 0;
}
