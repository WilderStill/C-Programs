#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<long long,long long>
using namespace std;
struct Node
{
	ll x,y;
	ll pre;
}node[11451411];
struct Edge
{
	ll nxt,to; 
	ll len;
}edge[11451411];
ll n,m,tot,ans=INF<<1,hd[11451411],dis1[11451411],dis2[11451411];
void addEdge(ll u,ll v,ll w)
{
	edge[++tot].len=w;
	edge[tot].to=v;
	edge[tot].nxt=hd[u];
	hd[u]=tot;
}
void Dijkstra()
{
	memset(dis1,INF,sizeof dis1);
    memset(dis2,INF,sizeof dis2); 
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push(make_pair(0,1));
    dis1[1]=0;
    while(!q.empty())
    {
        ll top=q.top().second,val=q.top().first;
        q.pop(); 
        if(val>dis2[top])continue;
        for(ll i=hd[top];i;i=edge[i].nxt)
        {
            ll to=edge[i].to;
            if(dis1[to]>val+edge[i].len)
            {   
			    dis2[to]=dis1[to];
                dis1[to]=val+edge[i].len;
                q.push(make_pair(dis1[to],to));
            } 
            if(dis2[to]>val+edge[i].len&&val+edge[i].len>dis1[to])
            {
            	dis2[to]=val+edge[i].len; 
            	q.push(make_pair(dis2[to],to));
            }    
        }
    }
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for(ll i=1,u,v,w;i<=m;i++)
	{
		scanf("%lld%lld%lld",&u,&v,&w);
		addEdge(u,v,w),addEdge(v,u,w);
	}
	Dijkstra();
	printf("%lld",dis2[n]);
	return 0;
}
