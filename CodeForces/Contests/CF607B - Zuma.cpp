#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define M 1145
using namespace std;
int n,f[M][M],s[M];
int main()
{
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>s[i];
	memset(f,INF,sizeof(f));
	for(int i=1;i<=n;++i)f[i][i]=f[i][i-1]=1;
	for(int len=1;len<=n;++len) 
		for(int i=1;i+len<=n;++i)
		{
			if(s[i]==s[i+len])f[i][i+len]=min(f[i][i+len],f[i+1][i+len-1]);
			for(int j=i;j<i+len;++j)f[i][i+len]=min(f[i][i+len],f[i][j]+f[j+1][i+len]);
		}
	printf("%d",f[1][n]);
	return 0;
}
