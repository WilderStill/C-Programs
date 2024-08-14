#include <bits/stdc++.h>
using namespace std;
struct node
{
	int va, nt, l;
}e[1000086];
int n,m,c,cnt,h[1000086],d[1000086],sum[1000086],v[1000086],S[1000086];
const int inf = 0x3f3f3f3f;
void AddEdge (int u, int v, int w)
{
	e[++cnt].va=v;
    e[cnt].nt=h[u];
    e[cnt].l=w;
    h[u]=cnt;
}
void SPFA()
{
	queue <int> q;
	int s=0;
	for(int i=1;i<=n;i++)d[i]=-inf;
	d[s]=0;
	sum[s]=1;
	v[s]++;
	q.push(s);
	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		sum[cur]=0;
		for(int p=h[cur];p>0;p=e[p].nt)
			if(d[e[p].va]<d[cur]+e[p].l)
			{
				d[e[p].va]=d[cur]+e[p].l;
				v[e[p].va]++;
				if (v[e[p].va]>=n+1)return;
				if (!sum[e[p].va])
				{
					q.push(e[p].va);
					sum[e[p].va] = 1;
				}
			}
	}
	return;
}

int main()
{
	scanf("%d%d%d", &n, &m, &c);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&S[i]);
		AddEdge(0,i,S[i]);
	}
	for(int i=1,u,v,w;i<=c;i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		AddEdge(u,v,w);
	}
	SPFA();
	for(int i=1;i<=n;i++)printf("%d\n",d[i]);
	return 0;
}
