#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
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
const ll mod=1000000007;
int Primetot,Prime[21451411],sum[21451411],phi[21451411],d[21451411],num[21451411],g[21451411];
bool isPrime[21451411];
void Eulerphi(ll n)
{
	d[1]=1;
	for(ll i=2;i<=n;++i) 
	{
		if(!isPrime[i])Prime[++Primetot]=i,phi[i]=i-1,num[i]=1,d[i]=2;
		for(int j=1;j<=Primetot&&i*Prime[j]<=n;++j)
		{
			isPrime[Prime[j]*i]=1;
			if(i%Prime[j]==0)
			{
				num[i*Prime[j]]=num[i]+1;
				d[i*Prime[j]]=d[i]/(num[i]+1)*(num[i*Prime[j]]+1);
				break;
			}
			num[i*Prime[j]]=1;
            d[i*Prime[j]]=d[i]*2;
		}
	}
	for(int i=1;i<=n;++i)sum[i]=(d[i]+sum[i-1])%mod;
}
int main()
{
	ll ans=0;
	isPrime[1]=1;Prime[1]=1;
	ll n=read(),A=read(),B=read(),C=read();
	g[n]=read();
	Eulerphi(n+10);
	for(int i=n;i>1;--i)g[i-1]=(A*g[i]%mod*g[i]%mod+B*g[i]%mod+C)%mod;
	for(int i=1;i<=n;++i)
	{
		ll cnt=(n+sum[i-1])%mod;
		(cnt*=g[i])%=mod;
		(cnt*=(n-i+1))%=mod;
		ans=(ans+cnt)%mod;
	}
	write(ans);
	return 0;
}
