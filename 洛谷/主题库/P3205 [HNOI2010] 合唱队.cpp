#include<bits/stdc++.h>
#define Maxn 1145
#define mod 19650827
using namespace std;
int h[Maxn],f[Maxn][Maxn],n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
	    scanf("%d",&h[i]);
	    f[i][i]=1;
	}
	for(int i=1;i<=n;i++)
	    for(int j=1;i+j<=n;j++)
		{
			int k=i+j;
			if(j!=k-1)
			{
				if(h[j]<h[k])f[k][j]+=f[j+1][k];
				if(h[k]>h[j])f[j][k]+=f[k-1][j];
			}
			if(h[j]<h[j+1])f[k][j]+=f[k][j+1];
	    	if(h[k]>h[k-1])f[j][k]+=f[j][k-1];
	    	f[j][k]%=mod,f[k][j]%=mod;
		}
	printf("%d",(f[1][n]+f[n][1])%mod);
	return 0;
}
