#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll k,n,tmp;
int main()
{
    scanf("%lld%lld",&n,&k);
    tmp=n;
    for(ll i=2;i<=k;i++)
    {
    	n*=tmp;
    	if(n>1e9)
    	{
    		printf("-1");
    		return 0;
		}
	}
	printf("%lld",n);
    return 0;
}
