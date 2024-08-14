#include<bits/stdc++.h>
#define ll long long
using namespace std; 
ll n,m,ans,f[114514];
int main()
{
    scanf("%lld%lld",&n,&m);
    if(n>m)swap(n,m);
    for(ll i=n;i;i--)
	{
        f[i]=(n/i)*(m/i);
        for(ll j=i<<1;j<=n;j+=i)f[i]-=f[j];
        ans+=f[i]*((i<<1)-1);
    }
    printf("%lld",ans);
	return 0;
}
