#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define M 315
using namespace std;
ll n,m,f[M][M][M][2];
struct candle
{
	ll x,y;
}pos[M];
bool cmp(candle a,candle b){return a.x<b.x;}
int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;++i)scanf("%lld%lld",&pos[i].x,&pos[i].y);
	pos[++n]={0,0};
	sort(pos+1,pos+n+1,cmp);
	ll st=-1;
	for(ll i=1;i<=n;++i)
		if(!pos[i].y){st=i;break;}
	memset(f,-INF,sizeof f);
	for(ll i=0;i<=n;++i)f[st][st][i][0]=f[st][st][i][1]=0;
	for(ll len=2;len<=n;++len)
		for(ll i=1,j=len;j<=n;++i,++j)
			for(ll k=0;k<=n;++k)
			{
				f[i][j][k][0]=max(max(f[i+1][j][k][0]-(pos[i+1].x-pos[i].x)*k,f[i+1][j][k+1][0]-(pos[i+1].x-pos[i].x)*(k+1)+pos[i].y),max(f[i+1][j][k][1]-(pos[j].x-pos[i].x)*k,f[i+1][j][k+1][1]-(pos[j].x-pos[i].x)*(k+1)+pos[i].y));
				f[i][j][k][1]=max(max(f[i][j-1][k][0]-(pos[j].x-pos[i].x)*k,f[i][j-1][k+1][0]-(pos[j].x-pos[i].x)*(k+1)+pos[j].y),max(f[i][j-1][k][1]-(pos[j].x-pos[j-1].x)*k,f[i][j-1][k+1][1]-(pos[j].x-pos[j-1].x)*(k+1)+pos[j].y));
			}
	ll ans=0;
	for(ll i=1;i<=n;++i)
		for(ll j=i;j<=n;++j)
			for(ll k=0;k<=n;++k)
				ans=max(ans,max(f[i][j][k][0],f[i][j][k][1]));
	printf("%lld",ans);
	return 0;
}
