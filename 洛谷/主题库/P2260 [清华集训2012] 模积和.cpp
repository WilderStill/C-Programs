#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=19940417;
inline ll read()
{
    ll x=0,f=1;
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
ll n,k,l=1,r,inv2=9970209,inv6=3323403,ans1,ans2,ans3;
int main()
{
    ll n=read(),m=read();
    if(n>m)swap(n,m);
    l=1,r=0,ans1=n*n%mod;
    while(l<=n)
    {
        r=n/(n/l);
        ans1=(ans1-(r*(r+1)%mod*inv2%mod-l*(l-1)%mod*inv2%mod+mod)%mod*(n/l)%mod+mod)%mod;
        l=r+1;
    }
    l=1,r=0,ans2=m*m%mod;
    while(l<=m)
    {
        r=m/(m/l);
        ans2=(ans2-(r*(r+1)%mod*inv2%mod-l*(l-1)%mod*inv2%mod+mod)%mod*(m/l)%mod+mod)%mod;
        l=r+1;
    }
    l=1,r=0,ans3=0;
	while(l<=n)
	{
		r=min(n/(n/l),m/(m/l));
		ans3=(ans3+(r-l+1)%mod*n%mod*m%mod-(r*(r+1)%mod*inv2%mod-l*(l-1)%mod*inv2%mod+mod)%mod*((n/l)*m%mod+(m/l)*n%mod)%mod+(r*(r+1)%mod*(2*r+1)%mod*inv6%mod-(l-1)*l%mod*(2*l-1)%mod*inv6%mod+mod)%mod*(n/l)*(m/l)%mod)%mod;
		l=r+1;
	}
    write((ans1*ans2%mod-ans3+mod)%mod);
    return 0;
}

