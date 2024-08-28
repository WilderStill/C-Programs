#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll bit[144],f[144][20];
ll dfs(ll n,bool is_max,bool lead,ll num,ll sum)
{
    if(!n)return sum;
    if(!is_max&&lead&&~f[n][sum])return f[n][sum];
    ll m=is_max?bit[n]:9;
    ll ans=0;
    for(ll i=0;i<=m;i++)
        ans+=dfs(n-1,is_max&&i==m,lead||i,num,sum+((i==num)&&(i||lead)));
    if(!is_max&&lead)f[n][sum]=ans;
    return ans;
}
ll dp_(ll x,ll num)
{
    ll len=0;
    while(x)
    {
        bit[++len]=x%10;
        x/=10;
    }
    return dfs(len,1,0,num,0);
}
int main()
{
    ll n;
	memset(f,-1,sizeof(f));
	scanf("%lld",&n);
    for(ll i=0;i<=9;++i)printf("%lld\n",dp_(n,i));
}
