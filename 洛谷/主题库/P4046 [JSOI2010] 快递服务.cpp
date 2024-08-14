#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int t,l,n,ans,f[2][214][214],c[214][214],q[1145];
int main()
{
	memset(f,INF,sizeof(f));
    scanf("%d",&l);
    for(int i=1;i<=l;++i)
        for(int j=1;j<=l;++j)
            scanf("%d",&c[i][j]);
    f[0][1][2]=0;q[0]=3;n=1;
    while(scanf("%d",&q[n])!=EOF)++n;
    for(int i=0;i<n;++i)
    {
    	memset(f[i+1&1],INF,sizeof(f[i+1&1]));
        for(int j=1;j<=l;++j)
            for(int k=1;k<=l;++k)
            {
                if(j==q[i]||k==j||k==q[i])continue;
                f[i+1&1][q[i]][k]=min(f[i+1&1][q[i]][k],f[i&1][j][k]+c[j][q[i+1]]);
                f[i+1&1][j][q[i]]=min(f[i+1&1][j][q[i]],f[i&1][j][k]+c[k][q[i+1]]);
                f[i+1&1][j][k]=min(f[i+1&1][j][k],f[i&1][j][k]+c[q[i]][q[i+1]]);
            }
	}
    ans=INF;
    for(int i=1;i<=l;++i)
        for(int j=1;j<=l;++j)
        {
        	if(i==q[n]||i==j||j==q[n])continue;
        	ans=min(f[n&1][i][j],ans);
		}
    printf("%d",ans);
	return 0;
}
