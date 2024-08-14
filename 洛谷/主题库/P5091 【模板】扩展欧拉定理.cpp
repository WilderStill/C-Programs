#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,tmp,bs,phi=1;
bool fg;
inline ll read()
{
	register ll x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		if(x>=phi){x%=phi;fg=1;}
		ch=getchar();
	}
	return x;
}
ll qpow(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		if(y&1)res=res*x%m;
		y>>=1;
		x=x*x%m;
	}
	return res;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	n%=m;
	tmp=m;
	for(ll i=2;i*i<=tmp;i++)
	{
		if(tmp%i)continue;
		phi*=i-1;
		tmp/=i;
		while(!(tmp%i))phi*=i,tmp/=i;
	}
	if(tmp>1)phi*=(tmp-1);
    bs=read();
    if(bs>=phi){bs%=phi;fg=1;}
    if(fg){bs+=phi;}
	printf("%lld",qpow(n,bs));
	return 0;
}
