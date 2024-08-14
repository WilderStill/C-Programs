#include<bits/stdc++.h>
#define M 1145
using namespace std;
int ans,n,k,f[M][M];
pair<int,int>dot[M];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d%d",&dot[i].first,&dot[i].second);
	sort(dot+1,dot+n+1);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=k;j++)
			f[i][j]=1+j;
	for(int i=2;i<=n;i++)
		for(int j=i-1;j>=1;j--) 
		{
			if(dot[j].second>dot[i].second)continue;
			int tmp=dot[i].first-dot[j].first+dot[i].second-dot[j].second-1;
			for(int l=tmp;l<=k;l++)f[i][l]=max(f[i][l],f[j][l-tmp]+tmp+1);
		}
	for(int i=1;i<=n;i++)ans=max(ans,f[i][k]);
	printf("%d",ans);
	return 0;
}
