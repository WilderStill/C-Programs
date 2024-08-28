#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define M 5145
using namespace std;
int n,p[M],f[M][M];
int main()
{
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>p[i];
	memset(f,INF,sizeof(f));
	for(int i=1;i<=n;++i)f[i][i]=1;
	for(int len=1;len<n;++len) 
		for(int i=1;i+len<=n;++i)
		{
			if(p[i]==p[i+len])f[i][i+len]=min(f[i+1][i+len],f[i][i+len-1]);
			else for(int j=i;j<i+len;++j)f[i][i+len]=min(f[i][i+len],f[i][j]+f[j+1][i+len]);
		}
	printf("%d",f[1][n]);
	return 0;
}
