#include<bits/stdc++.h>
using namespace std;
int n,a[1145],sum[1145],f[1145][1145];
int main()
{
	cin>>n;
	memset(f,0x3f3f3f3f,sizeof f);
	for(int i=1;i<=n;i++)cin>>a[i],sum[i]+=sum[i-1]+a[i],f[i][i]=0;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=n-i+1;j++)
			for(int k=j;k<i+j-1;k++)
				f[j][i+j-1]=min(f[j][i+j-1],f[j][k]+f[k+1][i+j-1]+sum[i+j-1]-sum[j-1]);
	cout<<f[1][n];
	return 0;
}
