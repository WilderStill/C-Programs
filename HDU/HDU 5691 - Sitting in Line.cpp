#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define M 16
using namespace std;
int f[1<<M][M],a[M],p[M],t,n;
int main()
{
	scanf("%d",&t);
	for(int T=1;T<=t;++T)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)scanf("%d%d",&a[i],&p[i]);
		for(int i=0;i<(1<<n);++i)
			for(int j=0;j<n;++j)
				f[i][j]=-INF;
		for(int i=0;i<n;++i)
			if(p[i]==0||p[i]==-1)
				f[1<<i][i]=0;
		for(int i=0;i<(1<<n);++i)
			for(int j=0;j<n;++j)
				if(f[i][j]!=-INF)
	                for(int k=0;k<n;++k)
	                        if(((1<<k)&i)==0&&(p[k]==__builtin_popcount(i)||p[k]==-1))
	                            f[i|(1<<k)][k]=max(f[i|(1<<k)][k],f[i][j]+a[j]*a[k]);
	    int ans=-INF;
	    for(int i=0;i<n;++i)ans=max(f[(1<<n)-1][i],ans);
		printf("Case #%d:\n%d\n",T,ans);
	}
	return 0;
}

