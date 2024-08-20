#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll T,x,y;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&x,&y);
		ll a=1,g=__gcd(x,y),b=(x*y)/(g*g);
		printf("%lld %lld\n",a,b);
	} 
	return 0;
}
