#include<bits/stdc++.h>
#define M 300010
#define ll long long
#define int long long
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
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
inline void write(ll x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
	return;
}
int hp[M][2],rt[M],s[M],fa[M],dep[M],dis[M],v[M],a[M],c[M],dx[M];
ll h[M],mk[M],tim[M],ans[M];
inline void pushdown(int x)
{
	if(!mk[x]&&tim[x]==1)return;
	if(hp[x][0])
	{
		tim[hp[x][0]]*=tim[x];
		mk[hp[x][0]]=mk[hp[x][0]]*tim[x]+mk[x];
		s[hp[x][0]]=s[hp[x][0]]*tim[x]+mk[x];
	} 
	if(hp[x][1])
	{
		tim[hp[x][1]]*=tim[x];
		mk[hp[x][1]]=mk[hp[x][1]]*tim[x]+mk[x];
		s[hp[x][1]]=s[hp[x][1]]*tim[x]+mk[x];
	}
	mk[x]=0,tim[x]=1;
}
inline int merge(int x,int y)
{
	if(!x||!y)return x+y;
	pushdown(x),pushdown(y);
	if(s[x]>s[y])swap(x,y);
	hp[x][1]=merge(hp[x][1],y);
	if(dis[hp[x][0]]<dis[hp[x][1]])swap(hp[x][0],hp[x][1]);
    dis[x]=dis[hp[x][1]]+1;  
	return x;
}
signed main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)h[i]=read(),rt[i]=-1;
	dep[1]=1,dis[0]=-1;
	for(int i=2;i<=n;++i)
	{
		fa[i]=read(),a[i]=read(),v[i]=read();
		dep[i]=dep[fa[i]]+1;
	}
	for(int i=1;i<=m;++i)
	{
		s[i]=read(),c[i]=read();
		tim[i]=1;
		if(~rt[c[i]])rt[c[i]]=merge(rt[c[i]],i);
		else rt[c[i]]=i;
	}
	for(int i=n;i;--i)
	{
		while(~rt[i])
		{
			if(s[rt[i]]<h[i])
			{
				dx[rt[i]]=i;
				pushdown(rt[i]);
				if(!hp[rt[i]][0])rt[i]=-1;
				else rt[i]=merge(hp[rt[i]][0],hp[rt[i]][1]);
				continue;
			}
			else break;
		}
		if(i==1)break;
		if(rt[i]==-1)continue;
		if(a[i])
		{
			tim[rt[i]]*=v[i];
			mk[rt[i]]*=v[i];
			s[rt[i]]*=v[i];
		}
		else
		{
			mk[rt[i]]+=v[i];
			s[rt[i]]+=v[i];
		}
		pushdown(rt[i]);
		if(~rt[fa[i]])rt[fa[i]]=merge(rt[fa[i]],rt[i]);
		else rt[fa[i]]=rt[i];
	}
	for(int i=1;i<=m;++i)++ans[dx[i]];
	for(int i=1;i<=n;++i)write(ans[i]),puts("");
	for(int i=1;i<=m;++i)write(dep[c[i]]-dep[dx[i]]),puts("");
	return 0;
}
