#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool check(int n)
{
	if(n==1)
	{
		return 0;
	}
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)return 0;
	}
	return 1;
}

int main()
{
	ll m=0,n;
	scanf("%lld",&n);
	for(ll i=1;i<=11451411;i++)
	{
		if(check(i))m++;
		if(m==n)
		{
			printf("%lld",i);return 0;
		}
	}
	
	return 0;
}
