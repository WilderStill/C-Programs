#include<bits/stdc++.h>
#define M 4145
using namespace std;
int n,m,ans,maxx[M],f[M][M],s[M];
bool edge[M][M];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)maxx[i]=1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&s[i]);
		for(int j=1;j<=s[i];j++)scanf("%d",&f[i][j]),edge[i][f[i][j]]=1;
	}
	while(true)
	{
		bool flag=0;
		for(int i=1;i<=m;i++)
		{
			int maxn=0;
			for(int j=f[i][1];j<=f[i][s[i]];j++)
				if(!edge[i][j])maxn=max(maxn,maxx[j]);
			maxn++;
			for(int j=1;j<=s[i];j++)
				if(maxx[f[i][j]]<maxn)maxx[f[i][j]]=maxn,flag=1;
		}
		if(!flag)break;
	}
	for(int i=1;i<=n;i++)ans=max(ans,maxx[i]);
	printf("%d",ans);
	return 0;
}
