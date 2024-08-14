#include<bits/stdc++.h>
#define ull unsigned long long
#define mod 998244353
using namespace std;
ull qpow(ull x,ull y)
{
    ull ans=1;
    while(y)
	{
        if(y&1)ans=ans*x%mod;
        y>>=1;
        x=x*x%mod;
    }
    return ans;
}
int main()
{
	ull n,k,ans=0;
	scanf("%llu%llu",&n,&k);
	printf("%llu",qpow(qpow(2,k)-1,n));
	return 0;
}
