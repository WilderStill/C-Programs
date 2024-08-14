#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct paper
{
	ll llx,lly,urx,ury,color;
}p[114514];
ll a,b,n,ans[114514];
void dfs(ll lx,ll ly,ll rx,ll ry,ll t,ll d)
{
	while(d<=n&&(lx>=p[d].urx||ly>=p[d].ury||rx<=p[d].llx||ry<=p[d].lly))++d;
	if(d>n)ans[t]+=(rx-lx)*(ry-ly);
	else
	{
		if(lx<p[d].llx)dfs(lx,ly,p[d].llx,ry,t,d+1),lx=p[d].llx;
		if(ly<p[d].lly)dfs(lx,ly,rx,p[d].lly,t,d+1),ly=p[d].lly;
		if(rx>p[d].urx)dfs(p[d].urx,ly,rx,ry,t,d+1),rx=p[d].urx;
		if(ry>p[d].ury)dfs(lx,p[d].ury,rx,ry,t,d+1),ry=p[d].ury;
	}
}
int main()
{
	scanf("%lld%lld%lld",&a,&b,&n);
	for(int i=1;i<=n;++i)
		scanf("%lld%lld%lld%lld%lld",&p[i].llx,&p[i].lly,&p[i].urx,&p[i].ury,&p[i].color);
	dfs(0,0,a,b,1,1);
	for(int i=1;i<=n;++i)
		dfs(p[i].llx,p[i].lly,p[i].urx,p[i].ury,p[i].color,i+1);
	for(int i=1;i<=a;++i)
		if(ans[i])printf("%lld %lld\n",i,ans[i]);
	return 0;
}
