#include<bits/stdc++.h>
using namespace std;
long long n,m,u,v,mp[66][66];
bool edge[66][66][64];
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
        scanf("%lld%lld",&u,&v);
        mp[u][v]=1;
        edge[u][v][0]=true;
    }
    for(int k=1;k<=55;k++)
	    for(int i=1;i<=n;i++)
    		for(int t=1;t<=n;t++)
    			for(int j=1;j<=n;j++)
    				if(edge[i][t][k-1]&&edge[t][j][k-1])
					{
					    edge[i][j][k]=true;
					    mp[i][j]=1;
					}
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
	printf("%lld",mp[1][n]==0x3f3f3f3f?-1:mp[1][n]);
}
