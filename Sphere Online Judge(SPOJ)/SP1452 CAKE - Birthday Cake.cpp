#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int V[1000],m,n,ans;
void dfs(int t,int s,int v,int r,int h)
{
	if(!t)
	{
	    if(v==n)ans=min(s,ans);
	    return;
	}
	if(v+V[t-1]>n||2*(n-v)/r+s>=ans)return;
	if(t^m)
	{
		for(int lastr=r-1;lastr>=t;--lastr)
	        for(int lasth=min((n-v-V[t-1])/(lastr*lastr),h-1);lasth>=t;--lasth)
	        	dfs(t-1,s+2*lastr*lasth,v+lastr*lastr*lasth,lastr,lasth);
	}
	else
	{
		for(int lastr=r-1;lastr>=t;--lastr)
	        for(int lasth=min((n-v-V[t-1])/(lastr*lastr),h-1);lasth>=t;--lasth)
	        	dfs(t-1,s+lastr*lastr+2*lastr*lasth,v+lastr*lastr*lasth,lastr,lasth);
	}
}
int main()
{
	int T=1;
	scanf("%d",&T);
	V[0]=0;
	for(int r=1;r<1000;++r)V[r]=V[r-1]+r*r*r;
	while(T--)
	{
		scanf("%d%d",&n,&m);
		ans=INF;
		dfs(m,0,0,n+1,n+1);
		printf("%d\n",ans==INF?0:ans);
	}
	return 0;
}
