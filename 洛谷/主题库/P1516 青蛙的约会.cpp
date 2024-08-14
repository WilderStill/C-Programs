#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll exgcd(ll a,ll b,ll&x,ll&y)
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	ll d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
int main()
{
	ll x,y,a,b,c,n,m;
	scanf("%lld%lld%lld%lld%lld",&x,&y,&a,&b,&c);
	m=b-a,n=x-y;
	if(m<0){n=-n,m=-m;}
	ll d=exgcd(m,c,x,y),k;
	k=c/d;
	if(n%d)puts("Impossible");
	else printf("%lld",((x*(n/d))%k+k)%k);
	return 0;
}
