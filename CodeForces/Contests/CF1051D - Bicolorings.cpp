#include<bits/stdc++.h>
#define ll long long
#define N 2010
using namespace std;
const ll p=998244353;
ll n,k,f[N][N][4];
int main()
{
	scanf("%lld%lld",&n,&k);
	f[1][2][0]=f[1][1][1]=f[1][1][2]=f[1][2][3]=1;
	for(ll i=2;i<=n;++i)
	{
		for(ll j=0;j<=k;++j)
		{
			f[i][j][0]=(f[i-1][j][0]%p+f[i-1][j-1][1]%p+f[i-1][j-1][2]%p+f[i-1][j-2][3]%p)%p;
	    	f[i][j][1]=(f[i-1][j][0]%p+f[i-1][j][1]%p+f[i-1][j-1][2]%p+f[i-1][j][3]%p)%p;
	    	f[i][j][2]=(f[i-1][j][0]%p+f[i-1][j-1][1]%p+f[i-1][j][2]%p+f[i-1][j][3]%p)%p;
	    	f[i][j][3]=(f[i-1][j-2][0]%p+f[i-1][j-1][1]%p+f[i-1][j-1][2]%p+f[i-1][j][3]%p)%p;
		}
	}
	printf("%lld",(f[n][k][0]%p+f[n][k][1]%p+f[n][k][2]%p+f[n][k][3]%p)%p);
    return 0;
}
