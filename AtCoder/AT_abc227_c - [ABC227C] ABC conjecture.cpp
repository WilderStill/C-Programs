#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans;
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=sqrt(n);i++)
    	for(ll j=i;j<=sqrt(n/i);j++)
            ans+=n/i/j-j+1;
    printf("%lld",ans);
    return 0;
}
