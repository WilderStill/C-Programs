#include<bits/stdc++.h>
#define M 11451411
#define int long long
using namespace std;
int m,n,w[M],v[M],f[M];
signed main()
{
	scanf("%lld%lld",&m,&n);
    for(int i=1;i<=n;i++)
		scanf("%lld%lld",&w[i],&v[i]);
    for(int i=1;i<=n;i++)
		for(int j=w[i];j<=m;j++)
			f[j]=max(f[j],f[j-w[i]]+v[i]);
   	printf("%lld",f[m]);
	return 0;
}
