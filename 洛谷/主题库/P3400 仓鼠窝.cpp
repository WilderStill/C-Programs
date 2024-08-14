#include<bits/stdc++.h>
#define ll unsigned long long
#define M 4145
using namespace std;
ll n,m,top,sq[M],f[M],sum[M],mp[M][M],ans;
int main()
{
	scanf("%llu%llu",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%llu",&mp[i][j]);
	for(int i=1;i<=n;i++,top=0)
		for(int j=1;j<=m;j++) 
		{
			if(!mp[i][j])f[j]=i;
			while(top&&f[sq[top]]<f[j])top--;
			sq[++top]=j;
			ans+=(sum[top]=sum[top-1]+(i-f[sq[top]])*(sq[top]-sq[top-1]));
		}
	printf("%llu",ans);	
}
