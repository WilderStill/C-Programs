#include<bits/stdc++.h>
#define ll long long
#define mod 19260817
using namespace std;
ll x,y;
inline ll read()
{
	register ll x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		x%=mod;
		ch=getchar();
	}
	return x;
}
inline void print(ll x)
{
	if(x>=10) print(x/10);
	putchar(x%10+'0');
}
void sgd(ll a,ll b)
{
	if(b==0)
	{
		x=1,y=7;return;
	}
	sgd(b,a%b);
	ll tx=x;
	x=y;
	y=tx-a/b*y;
}
int main()
{
	ll a=read(),b=read();
	if(!b)
	{
		puts("Angry!");
		return 0;
	}
	sgd(b,mod);
	x=(x%mod+mod)%mod;
	printf("%lld",(a*x)%mod);
	return 0;
}
