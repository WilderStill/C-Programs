#include<bits/stdc++.h>
#define M 1145
using namespace std;
int sum[M],n,ans;
bool f[M][M];
int main()
{
	scanf("%d",&n);
	for(int i=1,x;i<=n;++i)
	{
		scanf("%d",&x);
		sum[i]=sum[i-1]+x;
	}
	for(int i=1;i<=n;++i)f[i][i]=f[i][i-1]=1;
	for(int len=1;len<n;++len)
		for(int l=1,r=l+len;l<n&&r<=n;++r,++l)
		{
			int i=l,j=r;
			while(i+1<=j)
			{
				while(((!f[j][r])||sum[r]-sum[j-1]<sum[i]-sum[l-1])&&j>i)--j;
				if(sum[r]-sum[j-1]==sum[i]-sum[l-1]&&f[l][i]&&f[j][r]&&f[i+1][j-1])f[l][r]=1;
				++i;
			}
		}
	for(int i=1;i<=n;++i)
	    for(int j=i;j<=n;++j)
			if(f[i][j])
				ans=max(ans,sum[j]-sum[i-1]);
	printf("%d",ans);
}
