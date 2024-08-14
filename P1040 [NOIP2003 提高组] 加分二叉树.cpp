#include<bits/stdc++.h>
#define ll long long
#define M 1145 
using namespace std;
ll n,f[M][M],rt[M][M];
void print(ll l,ll r)
{
	if(l>r)return;
	printf("%lld ",rt[l][r]);
	if(l==r)return;
	print(l,rt[l][r]-1);
	print(rt[l][r]+1,r);
}
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld",&f[i][i]),f[i][i-1]=1,rt[i][i]=i;
	for(int l=1;l<n;++l)
		for(int i=1,j=i+l;j<=n;++i,++j)
		{
			f[i][j]=f[i+1][j]+f[i][i];
			rt[i][j]=i;
			for(int k=i+1;k<j;++k)
				if(f[i][j]<f[i][k-1]*f[k+1][j]+f[k][k])
					f[i][j]=f[i][k-1]*f[k+1][j]+f[k][k],rt[i][j]=k;
		}
	printf("%lld\n",f[1][n]);
	print(1,n);
	return 0;
}
