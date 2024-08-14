#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int t,l,n,ans,ansx,ansy,posx[2001],posy[2001],f[2][201][201],c[201][201],q[2001];
unsigned char path[2001][201][201];
int main()
{
	memset(f,INF,sizeof(f));
    scanf("%d%d",&l,&n);
    for(int i=1;i<=l;++i)
        for(int j=1;j<=l;++j)
            scanf("%d",&c[i][j]);
    f[0][1][2]=0;q[0]=3;
    for(int i=1;i<=n;++i)scanf("%d",&q[i]);
    for(int i=0;i<n;++i)
    {
    	memset(f[i+1&1],INF,sizeof(f[i+1&1]));
        for(int j=1;j<=l;++j)
            for(int k=1;k<=l;++k)
            {
                if(j==q[i]||k==j||k==q[i])continue;
                if(f[i+1&1][q[i]][k]>f[i&1][j][k]+c[j][q[i+1]])f[i+1&1][q[i]][k]=f[i&1][j][k]+c[j][q[i+1]],path[i+1][q[i]][k]=j;
                if(f[i+1&1][j][q[i]]>f[i&1][j][k]+c[k][q[i+1]])f[i+1&1][j][q[i]]=f[i&1][j][k]+c[k][q[i+1]],path[i+1][j][q[i]]=k;
                if(f[i+1&1][j][k]>f[i&1][j][k]+c[q[i]][q[i+1]])f[i+1&1][j][k]=f[i&1][j][k]+c[q[i]][q[i+1]],path[i+1][j][k]=0;
            }
	}
    ans=INF;
    for(int i=1;i<=l;++i)
        for(int j=1;j<=l;++j)
        {
        	if(i==q[n]||i==j||j==q[n])continue;
        	if(f[n&1][i][j]<ans)
        	{
        		ans=f[n&1][i][j];
        		ansx=i,ansy=j;
			}	
		}
	printf("%d\n",ans);
	for(int i=n-1;i>=0;i--)
	{
		posx[i+1]=ansx,posy[i+1]=ansy;
		if(path[i+1][ansx][ansy])
		{
			if(ansx==q[i])ansx=path[i+1][ansx][ansy];
			if(ansy==q[i])ansy=path[i+1][ansx][ansy];
		}
	}
	ansx=1,ansy=2;
	for(int i=0;i<n;i++)
	{
		if(posx[i+1]==q[i])ansx=6-ansx-ansy;
		if(posy[i+1]==q[i])ansy=6-ansx-ansy;
		printf("%d ",6-ansx-ansy);
	}
	return 0;
}
