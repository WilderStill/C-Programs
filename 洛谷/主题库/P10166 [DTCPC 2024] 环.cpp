#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[11451411],ans=1e18;
vector<ll> edge[11451411];
bool vis[11451411];
void dfs(ll x,ll minn)
{
    for(ll i=0;i<edge[x].size();i++)
	{
        ans=min(ans,minn+a[edge[x][i]]);
        dfs(edge[x][i],min(minn,a[edge[x][i]]));
    }
}
int main()
{
	scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(ll i=1,u,v;i<=m;i++)
	{
		scanf("%lld%lld",&u,&v);
        edge[u].push_back(v);
        vis[v]=1;
    }
    for(ll i=1;i<=n;i++)
        if(!vis[i])
			dfs(i,a[i]);
    sort(a+1,a+1+n);
    ans=min(ans,(a[1]+a[2])*2);
    printf("%lld",ans);
    return 0;
}
