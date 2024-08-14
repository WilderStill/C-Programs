#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b,mul,ans;
ll gcd(ll x,ll y)
{
	if(!y)return x;
	return gcd(y,x%y);
}
int main()
{
	scanf("%lld%lld",&a,&b);
	mul=a*b;
	if(a==b)
	{
		printf("1");
		return 0;
	}
	for(int i=2;i<=sqrt(mul);i++)
	{
		if(mul%i==0&&gcd(i,mul/i)==a)ans+=2;
	}
	printf("%lld",ans);
	return 0;
}
