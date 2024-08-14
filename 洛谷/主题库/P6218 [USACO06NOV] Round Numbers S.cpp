#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll bit[14411],f[14114][114];
ll dfs(ll n,bool is_max,bool lead,ll del)
{
    if(!n)return del>=114;
    if(!is_max&&!lead&&~f[n][del])return f[n][del];
    ll m=is_max?bit[n]:1;
    ll ans=0;
    for(ll i=0;i<=m;i++)
    {
        ans+=dfs(n-1,is_max&(i==m),lead&(i==0),del+(i==0?(lead?0:1):-1));
	}    
    if(!is_max&&!lead)f[n][del]=ans;
    return ans;
}
ll dp_(ll x)
{
    ll len=0;
    while(x)
    {
        bit[++len]=x%2;
        x/=2;
    }
    return dfs(len,1,1,114);
}
int main()
{
    ll m,n;
	memset(f,-1,sizeof(f));
    scanf("%lld%lld",&n,&m);
    printf("%lld",dp_(m)-dp_(n-1));
    return 0;
}
