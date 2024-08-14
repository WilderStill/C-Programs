#include<bits/stdc++.h>
#define ll long long
#define M 1145+145
#define N 10000
#define mod 998244353
using namespace std;
ll n,w,p[M],cnt,c[M][30],minn[M],ans=1;
bool prime(ll x)
{
    if(x<=1)return 0;
    for(ll i=2;i<=sqrt(x);i++)
        if(!(x%i))return 0;
    return 1;
}
int main()
{
    for(ll i=1;i<=N;i++)if(prime(i))p[++cnt]=i;
    memset(minn,mod,sizeof(minn));
    scanf("%lld%lld",&n,&w);
    for(ll i=1,pii;i<=n;i++)
    {
        scanf("%lld",&pii);
        for(ll j=1;j<=cnt;j++)
        {
        	ll tot=0;
            while(pii%p[j]==0)pii/=p[j],tot++;
            c[j][tot]++,minn[j]=min(minn[j],tot);
        }
    }
    for(ll i=1;i<=cnt;i++)
        while(!(w%p[i]))
        {
            w/=p[i];
            c[i][minn[i]]--;
			c[i][minn[i]+1]++;
            if(!c[i][minn[i]])minn[i]++;
        }
    for(ll i=1;i<=cnt;i++)
        for(ll j=1;j<30;j++)
            for(ll k=1;k<=c[i][j];k++)
                ans*=(j+1),ans%=mod;
    printf("%lld",ans);
    return 0;
}
