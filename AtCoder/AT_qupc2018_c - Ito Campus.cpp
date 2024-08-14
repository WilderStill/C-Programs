#include<bits/stdc++.h>
#define pl pair<ll,ll>
#define ll long long
#define M 1145
using namespace std;
const ll dx[4]={-1,1,0,0},dy[4]={0,0,1,-1};
ll pig[M][M],f[M][M],H,W,X;
char mp[M][M];
queue<pl>qf,qp;
int main()
{
	memset(pig,-1,sizeof(pig)),memset(f,-1,sizeof(f));
	scanf("%lld%lld%lld",&H,&W,&X);
	for(ll i=1;i<=H;++i)scanf("%s",mp[i]+1);
	for(ll i=1;i<=H;++i)
		for(ll j=1;j<=W;++j)
		{
			if(mp[i][j]=='@')pig[i][j]=0,qp.emplace(i,j);
			if(mp[i][j]=='S')f[i][j]=0,qf.emplace(i,j);
		}
	while(qp.size())
	{
		auto top=qp.front();qp.pop();
		ll x=top.first,y=top.second;
	    for(ll i=0;i<4;++i)
		{
			ll xx=x+dx[i],yy=y+dy[i];
			if(mp[xx][yy]=='#'||~pig[xx][yy])continue;
			pig[xx][yy]=pig[x][y]+1;
			qp.emplace(xx,yy);
	    }
	}  
	for(ll i=1;i<=H;++i)
		for(ll j=1;j<=W;++j)
			if(!~pig[i][j])pig[i][j]=X+1;
	while(qf.size())
	{
		auto top=qf.front();qf.pop();
		ll x=top.first,y=top.second;
		for(ll i=0;i<4;++i)
		{
			ll xx=x+dx[i],yy=y+dy[i];
			if(mp[xx][yy]=='#'||pig[xx][yy]<=X||~f[xx][yy])continue;
			f[xx][yy]=f[x][y]+1;
			qf.emplace(xx,yy);
		}
	}  
	for(ll i=1;i<=H;++i)
		for(ll j=1;j<=W;++j)
			if(mp[i][j]=='G')
			{
				printf("%lld",f[i][j]);
				return 0;
			}
	return 0;
}
