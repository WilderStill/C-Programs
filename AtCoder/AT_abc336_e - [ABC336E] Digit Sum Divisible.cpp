#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll bit[144],f[21][128][128][2],p;
ll dfs(ll n,ll s,ll sum,bool is_max)
{
	if(s<0) return 0;
	if(!n) return(!s&&!sum);
    if(~f[n][s][sum][is_max]) return f[n][s][sum][is_max];
    ll ans=0,m=is_max?bit[n]:9;
    for(ll i=0;i<=m;++i)
        ans+=dfs(n-1,s-i,(sum*10+i)%p,is_max&&i==bit[n]);
    f[n][s][sum][is_max]=ans;
    return ans;
}
ll dp_(ll x)
{
    ll len=0,ans=0;
    while(x)
    {
        bit[++len]=x%10;
        x/=10;
    }
    for(int i=1;i<=127;++i)
	{
		memset(f,-1,sizeof(f));
		p=i;
		ans+=dfs(len,i,0,1);
	}
    return ans;
}
int main()
{
    ll n;
    scanf("%lld",&n);
    printf("%lld",dp_(n));
}
