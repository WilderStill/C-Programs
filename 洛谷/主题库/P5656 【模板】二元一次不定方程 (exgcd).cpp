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
	ll T,x,y,a,b,c;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		ll d=exgcd(a,b,x,y);
		if(c%d){puts("-1");continue;}
		x*=c/d,y*=c/d;
		ll p=b/d,q=a/d,t=x<0;
		if(x<0)t=ceil((1.0-x)/p),x+=t*p,y-=t*q;
		else t=(x-1)/p,x-=t*p,y+=t*q;
		y<=0?printf("%lld %lld\n",x,y+q*(ll)ceil((1.0-y)/q)):printf("%lld %lld %lld %lld %lld\n",(y-1)/q+1,x,(y-1)%q+1,x+(y-1)/q*p,y);
	} 
	return 0;
}
