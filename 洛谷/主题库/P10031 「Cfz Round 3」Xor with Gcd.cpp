#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
	{
		ll n;
	    scanf("%lld",&n);
	    printf("%lld\n",(n&1?n:n^(n/2)));
	}
    return 0;
}
