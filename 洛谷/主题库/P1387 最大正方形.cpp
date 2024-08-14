#include<bits/stdc++.h>
#define M 2145
#define S(x,y) x*y
using namespace std;
int f[M][M],p[M][M];
int ans_sq,ans_rec,n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
			scanf("%d",&p[i][j]);
        	if (p[i][j]==1) f[i][j]=min(min(f[i][j-1],f[i-1][j]),f[i-1][j-1])+1;
        	ans_sq=max(ans_sq,f[i][j]);
		}
    printf("%d",ans_sq);
} 
