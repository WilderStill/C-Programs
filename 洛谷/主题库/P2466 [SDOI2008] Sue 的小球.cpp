#include<bits/stdc++.h>
#define eps 1e-18
#define INF 0x3f3f3f3f3f3f3f3f
#define M 1145
using namespace std;
long long n,c,l_,r_;
long double sum[M],x[M],y[M],w[M],f[M][M][2];
struct node
{
	long double x,y,w;
}egg[M];
bool cmp(node a,node b)
{
	return a.x<b.x;
}
int main()
{
	memset(f,-INF,sizeof f);
	scanf("%lld%lld",&n,&c);
	egg[1]={c*1.0,0,0};
	for(long long i=1;i<=n;++i)scanf("%llf",&egg[i+1].x);
	for(long long i=1;i<=n;++i)scanf("%llf",&egg[i+1].y);
	for(long long i=1;i<=n;++i)scanf("%llf",&egg[i+1].w);
	sort(egg+1,egg+n+2,cmp);
	for(long long i=1;i<=n+1;++i)
	{
		sum[i]=sum[i-1]+egg[i].w;
		if(fabs(egg[i].x-c)<=eps&&fabs(egg[i].y-0.0)<=eps)l_=r_=i;
	}
	f[l_][l_][0]=f[r_][r_][1]=0.0;
	for(long long l=1;l<=n+1;++l)
		for(long long i=1,j=i+l;j<=n+1;++i,++j)
		{
			f[i][j][0]=egg[i].y+max(f[i+1][j][0]-(egg[i+1].x-egg[i].x)*(sum[i]+sum[n+1]-sum[j]),f[i+1][j][1]-(egg[j].x-egg[i].x)*(sum[i]+sum[n+1]-sum[j]));
			f[i][j][1]=egg[j].y+max(f[i][j-1][0]-(egg[j].x-egg[i].x)*(sum[i-1]+sum[n+1]-sum[j-1]),f[i][j-1][1]-(egg[j].x-egg[j-1].x)*(sum[i-1]+sum[n+1]-sum[j-1]));
		}
	printf("%.3llf",max(f[1][n+1][0],f[1][n+1][1])/1000.0);
	return 0;
}
