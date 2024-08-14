#include<bits/stdc++.h>
#define ll long long
#define M 11451411
#define mod 998244353
using namespace std;
inline ll read()
{
	register char ch=getchar();
	register ll x=0,f=1;
	while(!isdigit(ch)){ch=getchar();if(ch=='-')f=-1;}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
inline void print(ll x)
{
	if(x>=10)print(x/10);
	putchar(x%10+'0');
}
inline ll Binary_gcd(ll x,ll y)
{
	if(!x)return y;
	if(!y)return x;
	if(x<y)swap(x,y);
    register ll Binx=__builtin_ctz(x),Biny=__builtin_ctz(y),minn=Binx<Biny?Binx:Biny,del;
    y>>=Biny;
    while(x)
    {
        x>>=Binx;
        del=y-x;
        Binx=__builtin_ctz(del);
        if(x<y)y=x;
        x=del<0?-del:del;
    }
    return y<<minn;
}
ll n,ans,sum,a[M],b[M];
int main()
{
	n=read();
	for(register ll i=1;i<=n;++i)a[i]=read();
	for(register ll i=1;i<=n;++i)b[i]=read();
	for(register ll i=1;i<=n;++i)
	{
		ans=0,sum=1;
		for(register ll j=1;j<=n;++j)
		{
			sum=sum*i%mod;
			ans=(ans+sum*Binary_gcd(a[i],b[j]))%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
