#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll l,r;
int main()
{
	scanf("%lld%lld",&l,&r);
	puts("YES");
	for(ll i=l;i<=r;i+=2)printf("%lld %lld\n",i,i+1);
    return 0;
}
