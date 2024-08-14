#include<bits/stdc++.h>
#define M 1145141
#define ll long long
#define lowbit(x) ((x)&(-(x)))
using namespace std;
long long b[M];
int n,m;
void add(int x, ll v)
{
    for(int i=x;i<=n;i+=lowbit(i))b[i]+=v;
}
ll query(int x)
{
    ll ans = 0;
    for(ll i=x;i;i-=lowbit(i))ans+=b[i];
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    ll last=0,now;
    for(int i=1;i<=n;i++)
	{
        scanf("%lld",&now);
        add(i,now-last);
        last=now;
    }
    for(int i=1,op,x,y;i<=m;i++)
	{
		ll k;
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d%lld",&x,&y,&k);
			add(x,k);
			add(y+1,-k);
		}
		else if(op==2)
		{
			scanf("%d",&x);
			printf("%lld\n",query(x));
		}
	}
    return 0;
}
