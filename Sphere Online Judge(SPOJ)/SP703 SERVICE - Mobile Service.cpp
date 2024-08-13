#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int t,l,n,ans,f[1145][214][214],c[214][214],q[1145];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(f,INF,sizeof(f));
        scanf("%d%d",&l,&n);
        for(int i=1;i<=l;++i)
            for(int j=1;j<=l;++j)
                scanf("%d",&c[i][j]);
        f[0][1][2]=0;q[0]=3;
        for(int i=1;i<=n;++i)scanf("%d",&q[i]);
        for(int i=0;i<n;++i)
            for(int j=1;j<=l;++j)
                for(int k=1;k<=l;++k)
                {
                    if(j==q[i]||k==j||k==q[i])continue;
                    f[i+1][q[i]][k]=min(f[i+1][q[i]][k],f[i][j][k]+c[j][q[i+1]]);
                    f[i+1][j][q[i]]=min(f[i+1][j][q[i]],f[i][j][k]+c[k][q[i+1]]);
                    f[i+1][j][k]=min(f[i+1][j][k],f[i][j][k]+c[q[i]][q[i+1]]);
                }
        ans=INF;
        for(int i=1;i<=l;++i)
            for(int j=1;j<=l;++j)
                ans=min(f[n][i][j],ans);
        printf("%d\n",ans);
    }
	return 0;
}
