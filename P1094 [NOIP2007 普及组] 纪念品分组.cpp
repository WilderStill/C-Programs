#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll w,ans=0,n,g[114514];
int main()
{
    scanf("%lld %lld",&w,&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&g[i]);
    sort(g+1,g+n+1);
    ll l=1,r=n;
    while(l<=r)
    {
        if(g[l]+g[r]<=w)l++;
        r--;
		ans++;
    }
    printf("%lld",ans);
    return 0;
}
