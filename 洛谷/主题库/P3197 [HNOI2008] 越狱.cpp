#include<bits/stdc++.h>
#define mod 100003
#define ll long long
#define pow2(x) x*x
using namespace std;
ll m,n;
ll exgcd(ll x,ll y)
{
    if(y==0) return 1;
    ll tmp=exgcd(x,y/2);
    if(y%2==0)
        return (pow2(tmp%mod))%mod;
    else if(y%2==1)
        return (pow2(tmp%mod)*(x%mod))%mod;
}
int main()
{
    scanf("%lld %lld",&m,&n);
    printf("%lld",(exgcd(m,n)-(m*exgcd(m-1,n-1))%mod+mod)%mod);
    return 0;
}
