#include<bits/stdc++.h>
#define M 214514
#define ll long long 
using namespace std;
ll n,m;
double p;	
struct edge{ll to,val;};
vector<edge>Edge[M];
void dfs(ll pos,ll sum,ll psum)
{
	if(pos==n)
	{
		p+=double(1.0*sum/psum);
		return;
	}
	for(auto i:Edge[pos])dfs(i.to,sum+i.val,psum*Edge[pos].size());
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for(ll i=1,x,y,z;i<=m;++i)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		Edge[x].push_back({y,z});
	}
	dfs(1,0,1);
	printf("%.2lf",p);
	return 0;
}
