#include<bits/stdc++.h>
#define M 1000100
#define ll long long
using namespace std;
const ll p=1000000007;
ll frac[M],inv[M],dg[M];
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
    dg[1]=0,dg[2]=1,dg[3]=2;frac[0]=1;
    for(ll i=4;i<=M-1;++i)dg[i]=(i-1)*(dg[i-1]+dg[i-2])%p;
    for(ll i=1;i<M;++i)frac[i]=frac[i-1]*i%p;
    inv[M-1]=qpow(frac[M-1],p-2);
    for(ll i=M-1;i>1;--i)inv[i-1]=inv[i]*i%p;
    
}
ll C(ll m,ll n)
{
    if(m<n)return 0;
    return frac[m]*inv[m-n]%p*inv[n]%p;
}
int main()
{
    ll T,m,n;
    init();
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&m);
        if(n-m==1)printf("0\n");
        else if(n==m)printf("1\n");
        else if(!m)printf("%lld\n",dg[n]);
        else printf("%lld\n",dg[n-m]*C(n,m)%p);
    }
}
