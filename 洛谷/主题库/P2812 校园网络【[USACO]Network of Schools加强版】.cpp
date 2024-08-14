#include<bits/stdc++.h>
#define ll long long
#define M 1145141
using namespace std;
ll n,m,hd[M],dfn[M],low[M],scc[M],scclen[M],in[M],out[M],ans,sccnum,tot,tim,cnt;
stack<ll>st;
bool inst[M];
struct edge
{
	ll to,nxt;
}edge[M];
inline void add_edge(ll x,ll y)
{
	edge[++tot].to=y;
	edge[tot].nxt=hd[x];
	hd[x]=tot;
}
inline void tarjan(ll x)
{
	dfn[x]=low[x]=++tim;
	st.push(x);
	inst[x]=1;
	for(register ll i=hd[x];i;i=edge[i].nxt)
	{
		if(!dfn[edge[i].to])
		{
			tarjan(edge[i].to);
			low[x]=min(low[x],low[edge[i].to]);
		}
		else if(inst[edge[i].to])
			low[x]=min(low[x],dfn[edge[i].to]);
	}
	if(dfn[x]==low[x])
	{
		++sccnum;
		while(true)
		{
			register ll t=st.top();
			st.pop();
			inst[t]=0;
			scc[t]=sccnum;
			++scclen[sccnum];
			if(x==t)break;
		}
	}
}
int main()
{
	scanf("%lld",&n);
	for(register ll i=1,x;i<=n;++i)
	{
		while(scanf("%lld",&x)&&x)add_edge(i,x);
	}
	for(register ll i=1;i<=n;++i)if(!dfn[i])tarjan(i);
	for(register ll i=1;i<=n;++i)
		for(register ll j=hd[i];j;j=edge[j].nxt)
			if(scc[i]!=scc[edge[j].to])
			{
				++in[scc[edge[j].to]];
				++out[scc[i]];
			}
	register ll me=0,you=0;
	for(register ll i=1;i<=sccnum;++i)
	{
		if(!in[i])++me;
		if(!out[i])++you;
	}
	if(sccnum==1)printf("1\n0");
	else printf("%lld\n%lld",me,max(me,you));
	return 0;
}
