#include<bits/stdc++.h>
using namespace std;
int n,k,p[114514],d[114514];
int find(int x)
{
	if(x!=p[x])
	{
		int o=find(p[x]);
		d[x]+=d[p[x]];
		p[x]=o;
	}
	return p[x];
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)p[i]=i,d[i]=0;
		int ans=0;
		for(int i=1;i<=k;i++)
		{
			int x,y,t;
			scanf("%d%d%d",&t,&x,&y);
			int px=find(x),py=find(y);
			if(x>n||y>n) ans++;
			else
			{
				if(t==1)
				{
					if(px==py&&(d[x]-d[y])%3!=0)ans++;
					else if(px!=py)
					{
						p[px]=py;
						d[px]=d[y]-d[x];
					}
				}
				else
				{
					if(px==py&&(d[x]-d[y]-1)%3)ans++;
					else if(px!=py)
					{
						p[px]=py;
						d[px]=d[y]-d[x]+1;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}
