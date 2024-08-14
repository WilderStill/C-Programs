#include<bits/stdc++.h>
#define ll long long
#define M 1000100
using namespace std;
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
ll n,a,b,c,syh,f[M],sum[M];
int main()
{
	n=read(),a=read(),b=read(),c=read();
	for(int i=1;i<=n;++i)
	{
		ll x=read();
		sum[i]=sum[i-1]+x;
	}
	for(int i=1;i<=n;++i)
	{
		f[i]=-M;
		for(int j=syh;j<i;++j)
		{
			if(f[i]<f[j]+a*(sum[i]-sum[j])*(sum[i]-sum[j])+b*(sum[i]-sum[j])+c)
			{
				f[i]=f[j]+a*(sum[i]-sum[j])*(sum[i]-sum[j])+b*(sum[i]-sum[j])+c;
				syh=j;
			}
		}	
	}	
	write(f[n]);
	return 0;
}
