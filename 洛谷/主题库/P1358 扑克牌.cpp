#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m,ans=1,a[11451][114];
int main()
{
    scanf("%lld%lld",&n,&m);
    a[0][0]=1;
    for(ll i=1;i<=10000;i++)
    	for(ll j=0;j<=100;j++)
      		a[i][j]=(a[i-1][j-1]+a[i-1][j])%10007;
    for(ll i=1;i<=m;i++)
    {
    	ll t;
        scanf("%lld",&t);
        ans=ans*a[n][t]%10007;
        n-=t;
    }
    printf("%lld",ans);
    return 0;
}
