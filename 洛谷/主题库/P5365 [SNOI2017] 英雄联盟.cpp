#include<bits/stdc++.h>
#define M 114514
using namespace std;
long long n,m,QB,ans=1,k[M],c[M],f[M];
int main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&k[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&c[i]);
		QB+=k[i]*c[i];
	}
	f[0]=1;
	for(int i=1;i<=n;i++)
		for(long long j=QB;j>=0;j--)
			for(int l=0;l<=k[i]&&l*c[i]<=j;l++)
				f[j]=max(f[j-l*c[i]]*l,f[j]);
	while(f[ans]<m&&ans<=QB)ans++;
	printf("%lld",ans);
	return 0;
}
