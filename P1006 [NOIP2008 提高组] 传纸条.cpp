#include<bits/stdc++.h>
using namespace std;
int n,m,mp[54][54],f[54][54][54][54];
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        	scanf("%d",&mp[i][j]);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=m;k++)
                for(int l=1;l<=n;l++)
                {
                    f[i][j][k][l]=max(max(f[i-1][j][k-1][l],f[i-1][j][k][l-1]),max(f[i][j-1][k][l-1],f[i][j-1][k-1][l]))+mp[i][j]+mp[k][l];
                    if(i==k&&j==l)f[i][j][k][l]-=mp[i][j];
                }
    printf("%d",f[m][n][m][n]);
}
