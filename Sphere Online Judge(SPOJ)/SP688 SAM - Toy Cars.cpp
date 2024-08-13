#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define M 500010 
using namespace std;
bool fg,vis[M];
ll n,m,pp,fail[M],pos[M],ans,num[M],raw[M];
priority_queue<pair<ll,ll>>q;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans=fg=0;
		memset(pos,INF,sizeof pos);
		memset(vis,0,sizeof vis);
		while(!q.empty())q.pop();
		scanf("%lld%lld%lld",&pp,&m,&n);
		for(int i=1;i<=n;++i)
			scanf("%lld",&raw[i]),num[i]=raw[i];
		sort(raw+1,raw+n+1);
		for(int i=1;i<=n;++i)
			num[i]=lower_bound(raw+1,raw+n+1,num[i])-raw;
		for(int i=n;i;--i)
		{
			fail[i]=pos[num[i]];
			pos[num[i]]=i;
		}
		for(int i=1;i<=n;++i)
		{
			if(ans==m)fg=1;
			if(!vis[num[i]])
			{
				++ans;
				vis[num[i]]=1;
				if(fg)
				{
					auto top=q.top();
					q.pop();
					vis[top.second]=0;
				}
			}
			q.push({fail[i],num[i]});
		}
		printf("%lld\n",ans);
	}
	return 0;
}
