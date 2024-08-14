#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[1145],sum[1145],f[1145][1145],ans=-1000000007;
int main()
{
	cin>>n;
	memset(f,-1000000007,sizeof f);
	for(int i=1;i<=n;i++)cin>>a[i],a[i+n]=a[i];
	for(int i=1;i<=2*n;i++)f[i][i]=0;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=2*n-i+1;j++)
			for(int k=j;k<i+j-1;k++)
			{
				f[j][i+j-1]=max(f[j][i+j-1],f[j][k]+f[k+1][i+j-1]+a[i+j-1]*a[j-1]*a[k]);
			}
	for(int i=1;i<=2*n;i++)
	{
		ans=max(f[i][n+i-1],ans);
	}
	cout<<ans;
	return 0;
}
