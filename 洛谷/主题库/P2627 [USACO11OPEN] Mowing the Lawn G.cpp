#include<bits/stdc++.h>
#define ll long long
#define M 1145141
#define qhd que[hd]
#define qtl que[tl]
using namespace std;
ll n,k,ans,sum[M],f[M][2],que[M],hd=1,tl=1;
int main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		ll cow;
		scanf("%lld",&cow);
		sum[i]=sum[i-1]+cow;
	}
	for(int i=1;i<=n;i++)
	{
		f[i][0]=max(f[i-1][0],f[i-1][1]);
		while(qhd<i-k&&hd<=tl)hd++;
		f[i][1]=f[qhd][0]-sum[qhd]+sum[i];
		while(f[i][0]-sum[i]>f[qtl][0]-sum[qtl]&&hd<=tl)tl--;
		que[++tl]=i;
	}
	ans=max(f[n][0],f[n][1]);
	printf("%lld",ans);
	return 0;
}
