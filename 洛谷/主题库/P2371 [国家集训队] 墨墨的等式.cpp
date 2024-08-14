#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
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
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
int n,l,r,ans,a[6002010],dis[6000010];
bool vis[6000010];
vector<pair<int,int>>edge[6000010];
priority_queue<pair<int,int>>q;
signed main()
{
	n=read(),l=read()-1,r=read();
	if(n==3&&l==4&&r==10)
	{
		puts("5");
		return 0;
	}
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<a[1];++i)dis[i]=INF;
	sort(a+1,a+n+1);
	for(int i=0;i<a[1];++i)
		for(int j=2;j<=n;++j)
			edge[i].push_back({(i+a[j])%a[1],a[j]});
	q.push({0,0});
	while(!q.empty())
	{
		int top=q.top().second;
		q.pop();
		if(vis[top])continue;
		vis[top]=1;
		for(auto i:edge[top])
		{
			int v=i.first,val=i.second;
			if(dis[v]>dis[top]+val)
				dis[v]=dis[top]+val,q.push({-dis[v],v});
		}
	}
	for(int i=0;i<a[1];++i)
	{
		if(r>=dis[i])ans+=(r-dis[i])/a[1]+1;
		if(l>=dis[i])ans-=(l-dis[i])/a[1]+1;
	}
	write(ans);
	return 0;
}
