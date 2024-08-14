#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define M 3001
#define ll long long 
using namespace std;
ll f[M][M],g[M][M],sum[M];
int main()
{
	int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
	{
		ll x;
        scanf("%lld",&x);
        sum[i]=x+sum[i-1];
    }
    memset(f,INF,sizeof f);
    f[0][0]=0;
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            for(int k=max(g[i][j-1],g[i-1][j]);k<=j;++k)
                if(f[i][j]>f[i-1][k]+(sum[j]-sum[k])*(sum[j]-sum[k]))
				{
                    f[i][j]=f[i-1][k]+(sum[j]-sum[k])*(sum[j]-sum[k]);
                    g[i][j]=k;
                }
	printf("%lld",m*f[m][n]-sum[n]*sum[n]);
    return 0;
}
