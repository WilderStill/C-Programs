#include<bits/stdc++.h>
#define M 20
#define ll long long
using namespace std;
int hd[M*M+10],now[M+10],son[M*M+10],v[M];
ll f[M][M];
int n,m,tot,cnt;
bool mp[M][M];
int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
void add(int x,int y)
{
	hd[++tot]=now[x];
	now[x]=tot;
	son[tot]=y;
}
void dfs(int x,int fa)
{
	for(int p=now[x],nxt=son[p];p;p=hd[p],nxt=son[p])
	{
		if(nxt==fa)continue;
		dfs(nxt,x);
	}
	for(int i=1;i<=cnt;i++)
	{
		f[x][i]=1;
		for(int p=now[x],nxt=son[p];p;p=hd[p],nxt=son[p])
		{
			if(nxt==fa)continue;
			ll tmp=0;
			for(int j=1;j<=cnt;j++)
				if(mp[v[i]][v[j]])
					tmp+=f[nxt][j];
			f[x][i]*=tmp;
			if(!f[x][i])break;
		}
	}
}
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		mp[x][y]=1;
		mp[y][x]=1;
	}
	for(int i=1;i<=n;i++) mp[i][i]=1;
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		add(x,y);
		add(y,x);
	}
	ll ans=0;
	for(int j=0;j<1<<n;j++)
	{
		cnt=0;
		ll sum=0;
		for(int i=1;i<=n;i++)
			if(j>>(i-1)&1)v[++cnt]=i;
		dfs(1,0);
		for(int i=1;i<=cnt;i++)sum+=f[1][i];
		if((n-cnt)&1)ans-=sum;
		else ans+=sum;
	}
	printf("%lld",ans);
}
