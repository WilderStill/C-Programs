#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll x,ll y)
{
	while(y!=0)
	{
    	x=x%y;
    	swap(x,y);
    }
    return x;
}
int main()
{
	ll x,y;
	scanf("%lld%lld",&x,&y);
	if(x<y)swap(x,y);
	printf("%lld %lld",gcd(x,y),x*y/gcd(x,y));
	return 0;
}
