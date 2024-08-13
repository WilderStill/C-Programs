#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define M 100514
using namespace std;
long long n,rt,f[M][3],val[M];
vector<long long>mp[M*2];
void dfs(long long x,long long fa)
{
	f[x][0]=0,f[x][2]=INF;
	for(auto v:mp[x])
	{
		if(v==fa)continue;
		dfs(v,x);
		f[x][2]=min(f[x][2]+min(f[v][1],f[v][2]),f[x][0]+f[v][1]);
		f[x][1]=min(f[x][1]+min(f[v][0],min(f[v][1],f[v][2])),INF);
		f[x][0]=min(f[x][0]+f[v][2],INF);
	}
}
int main()
{
	long long T;
	scanf("%lld",&T);
	while(T--)
	{
		rt=1;
		scanf("%lld",&n);
		for(long long i=1;i<=n;i++)mp[i].clear();
	    for(long long i=1;i<=n;i++)scanf("%lld",&val[i]),f[i][1]=val[i];
	    for(long long i=1,u,v;i<n;i++)
		{
			scanf("%lld%lld",&u,&v);
	        mp[u].push_back(v);
			mp[v].push_back(u);
	    }
	    dfs(rt,-1);
		printf("%lld\n",min(f[rt][1],f[rt][2]));
	}
	return 0;
}
