#include<bits/stdc++.h>
#define M 1000100
#define ll long long
using namespace std;
const ll p=1000000007;
ll frac[M],inv[M];
ll qpow(ll x,ll y)
{
    ll res=1;
    while(y)
    {
        if(y&1)res=x*res%p;
        x=x*x%p;
        y>>=1;
    }
    return res;
}
void init()
{
    frac[0]=1;
    for(ll i=1;i<M;++i)frac[i]=frac[i-1]*i%p;
    inv[M-1]=qpow(frac[M-1],p-2);
    for(ll i=M-1;i;--i)inv[i-1]=inv[i]*i%p;
}
ll C(ll m,ll n)
{
    if(m<n)return 0;
    return frac[m]*inv[m-n]%p*inv[n]%p;
}
int main()
{
    ll n;
    init();
    scanf("%lld",&n);
    printf("%lld",(2*C(2*n-1,n))%p-n);
}
