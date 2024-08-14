#include<bits/stdc++.h>
#define M 114514
#define ll long long
using namespace std;
struct nd
{
	int t,g,m;
}e[M],s[M];
ll n,ans;
bool cmp(nd x,nd y)
{
	return x.t<y.t;
}
ll Delta(ll b,ll c)
{
	ll dl=b*b-4*c;
	if(dl<0)return -1;
	return floor((sqrt(dl)-b)/2);
}
void dfs(ll x)
{
	ll nh=0,mf=1,ansn=0,tot=0;
	for(int i=1;i<=n;i++)
	{
		if(x&(1<<i-1))
		{ 
			s[++tot]=e[i];
			ansn+=e[i].m;
		}
	}
	for(int i=1;i<=tot;i++)
	{
		ll t=s[i].t-s[i-1].t,sum=0;
		for(int j=i;j<=tot;j++)
		{
			sum+=s[j].g;
			if(nh>=sum)continue;
			t=min(t,Delta(mf-s[j].t+s[i-1].t,sum-nh-mf*(s[j].t-s[i-1].t)));
		}
		if(t<0) return;
		mf+=t;
		nh+=mf*(s[i].t-s[i-1].t-t)-s[i].g;
	}
	ans=max(ans,ansn);
}

int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&e[i].t,&e[i].g,&e[i].m);
	sort(e+1,e+n+1,cmp); 
	for(int i=0;i<=(1<<n)-1;i++)dfs(i);
	printf("%lld",ans);
	return 0;
}
