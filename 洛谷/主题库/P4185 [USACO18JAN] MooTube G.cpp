#include<bits/stdc++.h>
#define M 100010
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
struct node
{
	int u,v,w;
}mp[M];
struct qry
{
	int k,v,id;
}syh[M];
int n,q,dg=1,f[M],fa[M],ans[M];
bool cmpm(node a,node b)
{
	return a.w>b.w;
}
bool cmpq(qry a,qry b)
{
	return a.k>b.k;
}
int findfa(int x)
{
	return fa[x]==x?x:fa[x]=findfa(fa[x]);
}
void dfs(int lim)
{
	for(int rt=dg;rt<n;++rt)
	{
		if(mp[rt].w<lim){dg=rt;break;}
		int fu=findfa(mp[rt].u),fv=findfa(mp[rt].v);
		if(fu^fv)
		{
			if(f[fu]>f[fv])
			{
				fa[fv]=fu;
				f[fu]+=f[fv];
			}
			else
			{
				fa[fu]=fv;
				f[fv]+=f[fu];
			}
		}
	}
}
int main()
{
	//freopen("lockdown.in","r",stdin);
	//freopen("lockdown.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;++i)fa[i]=i,f[i]=1;
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read(),w=read();
		mp[i]={u,v,w};
	}
	sort(mp+1,mp+n,cmpm);
	for(int i=1;i<=q;++i)
	{
		int K=read(),V=read();
		syh[i]={K,V,i};
	}
	sort(syh+1,syh+q+1,cmpq);
	syh[0]={1000000009,0,0};
	for(int i=1;i<=q;++i)
	{
		if(syh[i-1].k^syh[i].k)dfs(syh[i].k);
		ans[syh[i].id]=f[findfa(syh[i].v)]-1;
	}
	for(int i=1;i<=q;++i)
	{
		write(ans[i]);
		puts("");
	}
    return 0;
}

