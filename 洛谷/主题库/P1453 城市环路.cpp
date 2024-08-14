#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define M 1145141
using namespace std;
ll n,cnt,rt1,rt2,f[M][2],hd[M],val[M],fa[M];
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
void dp(ll x,ll fa)
{
    f[x][0]=0,f[x][1]=val[x];
    for(ll i=hd[x];i;i=edge[i].nxt)
    {
        ll v=edge[i].to;
        if(v!=fa)
        {
            dp(v,x);
            f[x][0]+=max(f[v][1],f[v][0]);
            f[x][1]+=f[v][0];
        }
    }
}
ll find(ll x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
	scanf("%lld",&n);
    for(ll i=1,x;i<=n;++i)scanf("%lld",&val[i]),fa[i]=i;
    for(ll i=1,x,y;i<=n;++i)
    {
    	scanf("%lld%lld",&x,&y);
    	if(find(x+1)==find(y+1))rt1=x+1,rt2=y+1;
    	else
    	{
    		addedge(x+1,y+1);
        	addedge(y+1,x+1);
        	fa[find(y+1)]=find(x+1);
		}
    }
    double k,ans1,ans2;
    scanf("%lf",&k);
    dp(rt1,0);ans1=1.0*f[rt1][0]; 
	dp(rt2,0);ans2=1.0*f[rt2][0];
    printf("%.1lf",k*max(ans1,ans2));
    return 0;
}
