#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
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
const int p=998244353;
vector<int>edge[1000100],egde[1000100];
int n,m,qs,a[1000100],t[1000100],mul[1000100],add[1000100],pos[1000100],cnt[1000100],ind[1000100];
queue<int>q;
void topo1()
{
	for(int i=0;i<=m;++i)
	{
		ind[i]=egde[i].size();
		if(!ind[i])q.push(i);
	}
	while(!q.empty())
	{
		int top=q.front();
		q.pop();
		for(auto v:edge[top])
		{
			mul[v]=1ll*mul[v]*mul[top]%p;
			--ind[v];
			if(!ind[v])q.push(v);
		}
	}
}
void topo2()
{
	for(int i=0;i<=m;++i)
	{
		ind[i]=edge[i].size();
		if(!ind[i])q.push(i);
	}
	while(!q.empty())
	{
		int top=q.front(),now=1;
		q.pop();
		for(int i=egde[top].size()-1;~i;--i)
		{
			int v=egde[top][i];
			cnt[v]=(cnt[v]+1ll*cnt[top]*now)%p;
			now=1ll*now*mul[v]%p;
			--ind[v];
			if(!ind[v])q.push(v);
		}
	}
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	m=read();
	mul[0]=1;
	for(int i=1;i<=m;++i)
	{
		t[i]=read();
		if(t[i]==1)
		{
			pos[i]=read(),add[i]=read();
			mul[i]=1;
		}
		if(t[i]==2)mul[i]=read();
		if(t[i]==3)
		{
			mul[i]=1;
			int k=read();
			for(int j=1;j<=k;++j)
			{
				int x=read();
				edge[x].push_back(i);
				egde[i].push_back(x);
			}
		}
	}
	qs=read();
	cnt[0]=1;
	for(int i=1;i<=qs;++i)
	{
		int x=read();
		egde[0].push_back(x);
		edge[x].push_back(0);
	}
	topo1();
	topo2();
	for(int i=1;i<=n;++i)a[i]=1ll*a[i]*mul[0]%p;
	for(int i=1;i<=m;++i)
		if(t[i]==1)
			a[pos[i]]=(a[pos[i]]+1ll*cnt[i]*add[i])%p;
	for(int i=1;i<=n;++i)
		write(a[i]),putchar(' ');
    return 0;
}

