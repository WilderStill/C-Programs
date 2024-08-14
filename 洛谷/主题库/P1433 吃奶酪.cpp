#include<bits/stdc++.h>
#define M 16
#define db double
#define INF 127
using namespace std;
int n;
db x[M],y[M],ans,f[4<<M][M];
db dist(db x1,db y1,db x2,db y2){return sqrt(pow(x1-x2,2)+pow(y1-y2,2));}
int main()
{
	memset(f,INF,sizeof(f));
	ans=f[0][0];
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%lf%lf",&x[i],&y[i]);
	for(int i=0;i<n;i++)f[1<<i][i]=dist(0,0,x[i],y[i]);
	for(int i=1;i<(1<<n);i++)
		for(int j=0;j<n;j++)
			if(i&(1<<j))
				for(int k=0;k<n;k++)
					if((i&(1<<k))&&j!=k)
						f[i][j]=min(f[i][j],f[i-(1<<j)][k]+dist(x[j],y[j],x[k],y[k]));
	for(int i=0;i<n;i++)ans=min(ans,f[(1<<n)-1][i]);
	printf("%.2f",ans);
}
