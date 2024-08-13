#include<bits/stdc++.h>
#define M 1000100
#define ll long long
using namespace std;
const ll p=1000000007;
ll frac[M],inv[M];
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))
	{
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch))
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline void write(ll x)
{
    if(x<0)
	{
        putchar('-');
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
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
int c[1004],sum[1004];
ll ans=1;
int main()
{
	init();
	int k=read();
	for(int i=1;i<=k;++i)c[i]=read(),sum[i]=sum[i-1]+c[i];
	for(int i=1;i<=k;++i)
	{
		(ans*=C(sum[i]-1,c[i]-1))%=p;
	}
	write(ans);
	return 0;
}

