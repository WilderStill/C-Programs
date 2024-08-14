#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f(ll a)
{
	if(a==1||a==2)return 1;
	return f(a-1)+f(a-2);
}
int main()
{
	ll n,p;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&p);
		printf("%lld\n",f(p));
	}
    return 0;
}
