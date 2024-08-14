#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll a,b;
int main()
{
	scanf("%llu%llu",&a,&b);
	if(a==b)printf("%llu",a*(a+1)/2);
	else 
	{
		ll gcd_=__gcd(a,b);
		if((a/gcd_)&1&&(b/gcd_)&1)printf("%llu",(a*b+gcd_)/2);
		else if(a&1&&b&1)printf("%llu",(a*b+1)/2);
		else printf("%llu",(a*b)/2);
	}
	return 0;
}
