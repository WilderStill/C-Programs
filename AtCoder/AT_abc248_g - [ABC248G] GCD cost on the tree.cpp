#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
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
inline void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	putchar(x%10+48);
	write(x/10);
}
const int mod=998244353;
int tot,maxx,sum,hd[400010],cnt[400010],len[400010],res[400010],vis[400010],ans[400010];
vector<int>prm[400001];
struct node
{
	int to,nxt;
}edge[400010];
void addedge(int u,int v)
{
	edge[++tot].to=v;
	edge[tot].nxt=hd[u];
	hd[u]=tot;
}
inline void dfs(int x,int fa)
{
    cnt[x]=len[x]=1;
	res[x]=vis[x]=0;
    for(int i=hd[x];i;i=edge[i].nxt)
	{
        int v=edge[i].to;
        if(!vis[v])continue;
        dfs(v,fa);
        res[x]=(res[x]+(1ll*cnt[x]*len[v]%mod+1ll*cnt[v]*len[x]%mod)%mod)%mod;
        len[x]=(len[x]+len[v]+cnt[v])%mod;
        cnt[x]=cnt[x]+cnt[v];
    }
    ans[fa]=(ans[fa]+res[x])%mod;
}
int main()
{
    int n=read();
    for(int i=1;i<=n;++i)
	{
        int x=read();
		maxx=max(maxx,x);
        for(int j=1;j<=sqrt(x);++j)
            if(!(x%j))
			{
                prm[j].push_back(i);
                if(j*j<x)prm[x/j].push_back(i);
            }
    }
    for(int i=1;i<n;++i)
	{
        int u=read(),v=read();
        addedge(u,v);
		addedge(v,u);
    }
    for(int i=maxx;i;--i)
	{
        if(prm[i].empty())continue;
        for(auto j:prm[i])vis[j]=1;
    	for(auto j:prm[i])if(vis[j])dfs(j,i);
        for(int j=2*i;j<=maxx;j+=i)ans[i]=(ans[i]-ans[j]+mod)%mod;
    }
    for(int i=1;i<=maxx;++i)sum=(sum+1ll*ans[i]*i%mod)%mod;
    printf("%d",sum);
    return 0;
}
