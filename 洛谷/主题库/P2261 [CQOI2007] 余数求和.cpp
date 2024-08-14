#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,l=1,r,ans;
int main()
{
    scanf("%lld%lld",&n,&k);
    ans=n*k;
    while(l<=n)
    {
        r=(k/l)?min(k/(k/l),n):n;
        ans-=(k/l)*(r-l+1)*(l+r)/2;
        l=r+1;
    }
    printf("%lld",ans);
    return 0;
}
