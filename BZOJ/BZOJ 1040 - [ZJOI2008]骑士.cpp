#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define M 1145141
using namespace std;
ll n,cnt,ans,rt,f[M][2],hd[M],val[M],fa[M];
bool vis[M];
struct node
{
	ll nxt,to;
}edge[M<<2];
void addedge(ll u,ll v)
{
	edge[++cnt].to=v;
	edge[cnt].nxt=hd[u];
	hd[u]=cnt;
}
void dp(ll x)
{
    vis[x]=1,f[x][0]=0,f[x][1]=val[x];
    for(ll i=hd[x];i;i=edge[i].nxt)
    {
        ll v=edge[i].to;
        if(v!=rt)
        {
            dp(v);
            f[x][0]+=max(f[v][1],f[v][0]);
            f[x][1]+=f[v][0];
        }
        else f[v][1]=-INF;
    }
}
ll find(ll x)
{
	vis[x]=1;
	return fa[x];
}
void find_circle(ll x)
{
    vis[x]=1,rt=x;
    do rt=find(rt);
	while(!vis[rt]);
    //while(!vis[fa[rt]])rt=fa[rt],vis[rt]=1;
    dp(rt);
    ll tmp=max(f[rt][0],f[rt][1]);
    dp(rt=find(rt));
    ans+=max(tmp,max(f[rt][0],f[rt][1]));
}
int main()
{
	scanf("%lld",&n);
    for(ll i=1,x;i<=n;++i)
    {
    	scanf("%lld%lld",&val[i],&x);
        addedge(x,i);
        fa[i]=x;
    }
    for(ll i=1;i<=n;++i)if(!vis[i])find_circle(i);
    printf("%lld",ans);
    return 0;
}
