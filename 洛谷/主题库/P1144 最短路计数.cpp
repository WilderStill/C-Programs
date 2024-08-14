#include<bits/stdc++.h>
#define p 100003
#define int long long
#define N 1145145
#define M 2511415
#define T true
#define F false
using namespace std;
int n,m,x,y,tot,j,k;
int head[N],to[M],nxt[M],dis[N],ans[N];
bool flag[N];
queue<int> q;
void add(int x,int y)
{
	to[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++)
		dis[i]=0x3f3f3f3f,flag[i]=F;
	dis[1]=0;
	flag[1]=T;
	ans[1]=1;
	q.push(1);
	while(!q.empty())
	{
		j=q.front();
		q.pop();
		flag[j]=F;
		for(int i=head[j];i!=0;i=nxt[i])
		{
			k=to[i];
			if(dis[k]>dis[j]+1)
			{
				dis[k]=(dis[j]+1+p)%p;
				ans[k]=(ans[j]+p);
				if(!flag[k])
				{
					q.push(k);
					flag[k]=T;
				}
			}
			else if(dis[k]==dis[j]+1)
			{
				ans[k]=(ans[k]+ans[j]+p)%p;
			}
		}
	}
	for(int i=1;i<=n;i++) printf("%lld\n",ans[i]%p);
	return 0;	
} 
