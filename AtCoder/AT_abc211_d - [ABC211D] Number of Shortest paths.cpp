#include<bits/stdc++.h>
#define p 1000000007
#define int long long
#define N 2145145
#define M 2511415
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
		dis[i]=0x3f3f3f3f,flag[i]=0;
	dis[1]=0;
	flag[1]=1;
	ans[1]=1;
	q.push(1);
	while(!q.empty())
	{
		j=q.front();
		q.pop();
		flag[j]=0;
		for(int i=head[j];i!=0;i=nxt[i])
		{
			k=to[i];
			if(dis[k]>dis[j]+1)
			{
				dis[k]=dis[j]+1;
				ans[k]=ans[j];
				if(!flag[k])
				{
		    		q.push(k);
					flag[k]=1;
				}
			}
			else if(dis[k]==dis[j]+1)
				ans[k]=(ans[k]+ans[j])%p;
		}
	}
	printf("%lld",ans[n]);
	return 0;	
} 
