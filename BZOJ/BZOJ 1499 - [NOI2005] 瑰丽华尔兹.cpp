#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define M 215
using namespace std;
int f[M][M][M],n,m,x,y,tk,ans=-INF;
char mp[M][M];
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&x,&y,&tk);
	for(int i=1;i<=n;++i)scanf("%s",mp[i]+1);
	memset(f,-INF,sizeof(f));
	f[0][x][y]=0;
	for(int k=1,s,t,d,tm;k<=tk;++k)
	{
		scanf("%d%d%d",&s,&t,&d);
		tm=t-s+1;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				switch(d)
				{
					case 1:
					{
						for(int l=0;l<=tm;++l)
						{
							if(mp[i+l][j]!='.')break;
							f[k][i][j]=max(f[k][i][j],f[k-1][i+l][j]+l);
						}
						break;
					}
					case 2:
					{
						for(int l=0;l<=tm;++l)
						{
							if(mp[i-l][j]!='.')break;
							f[k][i][j]=max(f[k][i][j],f[k-1][i-l][j]+l);
						}
						break;
					}
					case 3:
					{
						for(int l=0;l<=tm;++l)
						{
							if(mp[i][j+l]!='.')break;
							f[k][i][j]=max(f[k][i][j],f[k-1][i][j+l]+l);
						}
						break;
					}
					case 4:
					{
						for(int l=0;l<=tm;++l)
						{
							if(mp[i][j-l]!='.')break;
							f[k][i][j]=max(f[k][i][j],f[k-1][i][j-l]+l);
						}
						break;
					}
					default:break;
				}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			ans=max(ans,f[tk][i][j]);
	printf("%d",ans);
	return 0;
}
