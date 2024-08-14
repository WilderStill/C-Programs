#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[1145],sum[1145],fa[1145][1145],fb[1145][1145],ansa=1000000007,ansb=-1000000007;
int main()
{
	cin>>n;
	memset(fa,1000000007,sizeof fa);
	memset(fb,-1000000007,sizeof fb);
	for(int i=1;i<=n;i++)cin>>a[i],a[i+n]=a[i];
	for(int i=1;i<=2*n;i++)sum[i]+=sum[i-1]+a[i],fa[i][i]=fb[i][i]=0;
	for(int i=2;i<=2*n;i++)
		for(int j=1;j<=2*n-i+1;j++)
			for(int k=j;k<i+j-1;k++)
			{
				fa[j][i+j-1]=min(fa[j][i+j-1],fa[j][k]+fa[k+1][i+j-1]+sum[i+j-1]-sum[j-1]);
				fb[j][i+j-1]=max(fb[j][i+j-1],fb[j][k]+fb[k+1][i+j-1]+sum[i+j-1]-sum[j-1]);
			}
	for(int i=1;i<=2*n;i++)
	{
		ansa=min(fa[i][n+i-1],ansa);
		ansb=max(fb[i][n+i-1],ansb);
	}
	cout<<ansa<<endl<<ansb;
	return 0;
}
