#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define M 1145411
using namespace std;
ll n,m,k;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct edge
{
    ll to,nxt,dis;
}edge[M*5];
ll tot,hd[M];
void add(ll u,ll v,ll w)
{
    edge[++tot].nxt=hd[u];
    edge[tot].to=v;
    edge[tot].dis=w;
    hd[u]=tot;
}
struct node
{
    ll dis,pos;
    bool operator<(const node &x)const{return pos>x.pos;}
};
ll dis[M],czr[M];
bitset<M> vis,fl;
ll dijkstra(ll s)
{
    priority_queue<node> q;
    vis.reset();
    memset(dis,INF,sizeof(dis));
    q.push((node){s,0});
    dis[s]=0;
    while(!q.empty())
    {
        node s1=q.top();
        q.pop();
        ll u=s1.dis;
        if(fl[u]&&u!=s)return dis[u];
        if(!vis[u])
        {
            vis[u]=1;
            for(ll i=hd[u];i;i=edge[i].nxt)
                if(dis[edge[i].to]>dis[u]+edge[i].dis)
                {
                    dis[edge[i].to]=dis[u]+edge[i].dis;
                    q.push((node){edge[i].to,dis[edge[i].to]});
                }
        }
    }
    return INF;
}
int main()
{
	srand(time(0));
    ll T,p=0;
    T=read();
    while(T--)
    {
    	tot=0;++p;
    	memset(hd,0,sizeof(hd));
    	fl.reset();
    	n=read(),m=read(),k=read();
        for(ll i=1,x,y,z;i<=m;i++)
        {
            x=read(),y=read(),z=read();
            add(x,y,z);
        }
        for(ll i=1,x;i<=k;i++)scanf("%lld",&x),fl[x]=1,czr[i]=x;
        ll ans=INF,tp=0;
        while((double)clock()/CLOCKS_PER_SEC<0.95*p)
		{
			ll x=dijkstra(czr[rand()%k+1]);
			ans=min(ans,x);
			tp+=(x==ans);
			if(tp>100)break;
		}
        printf("%lld\n",ans);
    }
    return 0;
}
