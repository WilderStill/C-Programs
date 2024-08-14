#include<bits/stdc++.h>
#define M 1145141
#define ll long long
using namespace std;
ll n,f[M],g[M],num[M],sum[M];
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
    {
	    scanf("%lld",&num[i]);
	    sum[i]=sum[i-1]+num[i];
    }
    for(ll i=1,j;i<=n;i++)
    {
    	j=i-1;
    	while(j>=0&&sum[i]-sum[j]<g[j])j--;
	    f[i]=f[j]+i-j-1;
	    g[i]=sum[i]-sum[j];
    }
    printf("%lld",f[n]);
    return 0;
}
