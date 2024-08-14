#include<bits/stdc++.h>
#define M 1145
using namespace std;
int tb[M][M],f[M][M],n,m,ans=-1;
int main()
{
	scanf("%d%d",&m,&n);
	memset(tb,-11451411,sizeof(tb));
	memset(f,-11451411,sizeof(f));
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&tb[i][j]);
	for(int i=0;i<=m;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=max(f[i-1][j],max(f[i-1][j-1],f[i-1][j+1]))+tb[i][j];
	printf("%d",max(f[m][n/2+1],max(f[m][n/2],f[m][n/2+2])));
	return 0;
}
