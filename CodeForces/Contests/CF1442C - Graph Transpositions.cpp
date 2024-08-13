#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll p=998244353;
inline ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))
	{
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch))
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline void write(ll x)
{
    if(x<0)
	{
        putchar('-');
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
ll qpow(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		if(y&1)res=res*x%p;
		x=x*x%p;
		y>>=1;
	}
	return res;
}
struct edge
{
	bool val;
	ll to,nxt;	
}edge[400010];
ll n,m,hd[200010],tot=0,tim[200010],dis[200010][21];
void addedge(ll u,ll v,bool w)
{
	edge[++tot].val=w;
	edge[tot].to=v;
	edge[tot].nxt=hd[u];
	hd[u]=tot;
}
deque<ll>dq;
void bfs()
{
	memset(tim,0x3f,sizeof tim);
	dq.clear();
	tim[1]=0;
	dq.push_back(1);
	while(!dq.empty())
	{
		ll top=dq.front();
		dq.pop_front();
		for(ll i=hd[top];i;i=edge[i].nxt)
		{
			ll v=edge[i].to,val=edge[i].val^(tim[top]&1);
			if(val)
			{
				if(tim[v]>tim[top]+1)
				{
					tim[v]=tim[top]+1;
					dq.push_back(v);
				}
			}
			else
			{
				if(tim[v]>tim[top])
				{
					tim[v]=tim[top];
					dq.push_front(v);
				}
			}
		}
	}
}
queue<pair<ll,ll>>q;
void bfs1()
{
	memset(dis,0x3f,sizeof dis);
	dis[1][0]=0;
	q.push({1,0});
	while(!q.empty())
	{
		auto top=q.front();
		q.pop();
		for(ll i=hd[top.first];i;i=edge[i].nxt)
		{
			ll v=edge[i].to,val=edge[i].val^(top.second&1);
			if(top.second+val-tim[v]>=20)continue;
			if(dis[v][top.second+val-tim[v]]>dis[top.first][top.second-tim[top.first]]+1)
			{
				dis[v][top.second+val-tim[v]]=dis[top.first][top.second-tim[top.first]]+1;
				q.push({v,top.second+val});
			}
		}
	}
}
struct nd
{
	ll k,val;
	bool operator<(const nd &b)const
	{
		if(max(k,b.k)>20)return k<b.k;
		return (1<<k)+val<(1<<b.k)+b.val;
	}
}ans;
int main()
{
	n=read(),m=read();
	for(ll i=1;i<=m;++i)
	{
		ll u=read(),v=read();
		addedge(u,v,0);
		addedge(v,u,1);
	}
	bfs();
	bfs1();
	ans.k=0x3f3f3f3f,ans.val=0;
	for(ll i=0;i<20;i++)ans=min(ans,(nd){tim[n]+i,dis[n][i]});
	write((qpow(2,ans.k)-1+ans.val)%p);
	return 0;
}
