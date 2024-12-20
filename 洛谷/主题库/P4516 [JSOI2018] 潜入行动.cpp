#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
	return x*f;
}
inline void write(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+48);
	return;
}
const ll mod=1000000007;
vector<int>mp[100010];
int n,K,f[100010][110][2][2],g[110][2][2],size[100010];
inline void dfs(int pos,int fa)
{
	size[pos]=1;
	f[pos][0][0][0]=f[pos][1][1][0]=1;
	for(auto v:mp[pos])
	{
		if(v==fa)continue;
		dfs(v,pos);
		for(int i=0;i<=min(size[pos],K);++i)
		{
			g[i][0][0]=f[pos][i][0][0];
			g[i][0][1]=f[pos][i][0][1];
			g[i][1][0]=f[pos][i][1][0];
			g[i][1][1]=f[pos][i][1][1];
			f[pos][i][0][0]=0;
			f[pos][i][0][1]=0;
			f[pos][i][1][0]=0;
			f[pos][i][1][1]=0;
		}
		for(int i=0;i<=min(size[pos],K);++i)
			for(int j=0;j<=min(size[v],K-i);++j)
			{
				f[pos][i+j][0][0]=(f[pos][i+j][0][0]+1ll*g[i][0][0]*f[v][j][0][1])%mod;
				f[pos][i+j][0][1]=(f[pos][i+j][0][1]+1ll*g[i][0][1]*(f[v][j][0][1]+f[v][j][1][1])+1ll*g[i][0][0]*f[v][j][1][1])%mod;
				f[pos][i+j][1][0]=(f[pos][i+j][1][0]+1ll*g[i][1][0]*(f[v][j][0][0]+f[v][j][0][1]))%mod;
				f[pos][i+j][1][1]=(f[pos][i+j][1][1]+1ll*g[i][1][0]*(f[v][j][1][0]+f[v][j][1][1])+1ll*g[i][1][1]*(1ll*f[v][j][0][0]+f[v][j][0][1]+1ll*f[v][j][1][0]+f[v][j][1][1]))%mod;
			}
			size[pos]+=size[v];
	}
}
int main()
{
	n=read(),K=read();
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	dfs(1,0);
	write((f[1][K][0][1]+f[1][K][1][1])%mod);
	return 0;
}
