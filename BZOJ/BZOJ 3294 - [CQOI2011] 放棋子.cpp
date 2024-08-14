#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000009
using namespace std;
int g[35][35], f[35][35][15], c[1145][1145];
int x,n,m,C,ans;

int main()
{		
	scanf("%d%d%d",&n,&m,&C);
	for(int i=0;i<=m*n;i++)c[i][0] = 1;
	for (int i=1;i<m*n;i++)
		for(int j=1;j<=i;j++)
			c[i][j] = (c[i-1][j]+c[i-1][j-1])%mod;
	f[0][0][0] = 1;
	for(int k=1;k<=C;k++) 
	{
		scanf("%d",&x);
		memset(g,0,sizeof(g));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			if(i*j>=x)
			{
				g[i][j]=c[i*j][x];
				for(int l=1;l<=i;l++)
					for(int r=1;r<=j;r++)
						if(l<i||r<j)
							g[i][j]=((ll)g[i][j]-(ll)g[l][r]*c[i][l]%mod*c[j][r]%mod+mod)%mod;
			}
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				for(int l=0;l<i;l++)
					for(int r=0;r<j;r++)
					{
						int tx=i-l,ty=j-r;
						if(tx*ty>=x)
							f[i][j][k]=(f[i][j][k]+(ll)f[l][r][k-1]*g[tx][ty]%mod*c[n-l][tx]%mod*c[m-r][ty]%mod)%mod;
					}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans=(ans+f[i][j][C])%mod;
	printf("%d",ans);
	return 0;
}
