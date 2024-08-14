#include<bits/stdc++.h>
using namespace std;
long long n,m,u,v,w,mp[1145][1145];
int main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
		{          
            mp[i][j]=0x3f3f3f3f;
            if(i==j)mp[i][j]=0;
        }
    for(int i=1;i<=m;i++)
	{
        scanf("%lld%lld%lld",&u,&v,&w);
        mp[u][v]=min(mp[u][v],w);
        mp[v][u]=min(mp[v][u],w);
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
			{
                mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
                mp[j][i]=mp[i][j];
            }
    for(int i=1;i<=n;i++)
	{
        for(int j=1;j<=n;j++)
            printf("%lld ",mp[i][j]);
        printf("\n");
    }
}
