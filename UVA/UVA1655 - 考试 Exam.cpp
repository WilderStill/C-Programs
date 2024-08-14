#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans,cases=1;
int main()
{
    while(scanf("%lld",&n)!=EOF)
    {
    	ans=0;
    	for(ll i=1;i*i*i<=n;++i)
	    	for(ll j=i;i*j*j<=n;++j)
	    	{
	    		if(j==i)ans+=(3*(n/(i*j)-j)+1);
	    		else ans+=(6*(n/(i*j)-j)+3);
			}
		printf("Case %lld: %lld\n",cases,ans);
		++cases;
	}
    return 0;
}
