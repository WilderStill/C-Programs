#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1000000007;
ll n,k,l=1,r,ans;
int main()
{
    scanf("%lld%lld",&k,&n);
    ans=(n%mod)*(k%mod)%mod;
    while(l<=n)
    {
        r=(k/l)?min(k/(k/l),n):n;
        ans=(ans-(k/l)%mod*((r-l+1)%mod)%mod*((l+r)%mod)%mod*((mod+1)/2)%mod)%mod;
        l=r+1;
    }
    printf("%lld",(ans+mod)%mod);
    return 0;
}
