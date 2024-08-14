#include<bits/stdc++.h>
using namespace std;
int n,mp[14][14],f[14][14][14][14];
int main()
{
    scanf("%d",&n);
    while(true)
    {
        int x,y,v;
        scanf("%d%d%d",&x,&y,&v);
        if(!x&&!y&&!v)break;
        else mp[x][y]=v;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                for(int l=1;l<=n;l++)
                {
                    f[i][j][k][l]=max(max(f[i-1][j][k-1][l],f[i-1][j][k][l-1]),max(f[i][j-1][k][l-1],f[i][j-1][k-1][l]))+mp[i][j]+mp[k][l];
                    if(i==k&&j==l)f[i][j][k][l]-=mp[i][j];
                }
    printf("%d",f[n][n][n][n]);
}
