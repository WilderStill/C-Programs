#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define M 16
using namespace std;
int f[1<<M][M],mp[M][M],t,n,m;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<M;++i)
			for(int j=0;j<M;++j)
				mp[i][j]=INF;
		for(int i=0;i<M;++i)mp[i][i]=0;
		for(int i=0;i<(1<<n);++i)
			for(int j=0;j<n;++j)
				f[i][j]=INF;
		f[1][0]=0;
		for(int i=0,u,v,w;i<m;++i)
		{
			scanf("%d%d%d",&u,&v,&w);
			mp[u-1][v-1]=mp[v-1][u-1]=min(mp[u-1][v-1],w);
		}
		for(int k=0;k<n;++k)
			for(int i=0;i<n;++i)
				for(int j=0;j<n;++j)
					mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
		for(int i=0;i<(1<<n);++i)
			for(int j=0;j<n;++j)
				if(f[i][j]!=INF)
	                for(int k=0;k<n;++k)
	                    if(((1<<k)&i)==0)
	                        f[i|(1<<k)][k]=min(f[i|(1<<k)][k],f[i][j]+mp[j][k]);
	    int ans=INF;
	    for(int i=0;i<n;++i)ans=min(f[(1<<n)-1][i]+mp[i][0],ans);
		printf("%d\n",ans);
	}
	return 0;
}

