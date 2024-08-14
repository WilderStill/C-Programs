#include<bits/stdc++.h>
#define M 11451411
#define ll long long
using namespace std;
ll n,m,l; 
ll smul(ll x,ll y,ll mod)
{
	ll res=0;
	while(y)
	{
	    if(y&1)res=(res+x)%mod;
	    x=(x+x)%mod;
	    y>>=1;
	}
	return res%mod;
}
ll qpow(ll x,ll y,ll mod)
{
	ll res=1;
	while(y)
	{
		if(y&1)res=smul(res,x,mod);
		y>>=1;
		x=smul(x,x,mod);
	}
	return res;
}
void exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b){x=1,y=0;return;}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
int main()
{
	scanf("%lld%lld%lld",&n,&m,&l);
	ll x,y;
	exgcd(2,(n+1),x,y);
    x=(x%(n+1)+(n+1))%(n+1);
    x=qpow(x,m,(n+1));
	printf("%lld",smul(l,x,n+1));
	return 0;
}
