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
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
struct node
{
	int nxt,to,val;
}edge[2000010];
int hd[2000010],sum[2000010],tot;
void addedge(int u,int v,int w)
{
	edge[tot].to=v;
	edge[tot].val=w;
	edge[tot].nxt=hd[u];
	hd[u]=tot++;
}
void dfs(int pos,int fa)
{
	for(int i=hd[pos];~i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(v==fa)continue;
		sum[v]=sum[pos]^edge[i].val;
		dfs(v,pos);
	}
}
struct trie
{
	int ch[2];
}tr[2000010];
int cnt;
void build(int pos,int val)
{
	for(int i=(1<<30);i;i>>=1)
	{
		bool c=i&val;
		if(!tr[pos].ch[c])tr[pos].ch[c]=++cnt;
		pos=tr[pos].ch[c];
	}
}
int query(int pos,int val)
{
    int ans=0;
    for(int i=(1<<30);i;i>>=1)
	{
        bool c=i&val;
        if(tr[pos].ch[c^1])
		{
            ans+=i;
            pos=tr[pos].ch[c^1];
        }
        else pos=tr[pos].ch[c];
    }
    return ans;
}
int main()
{
	memset(hd,-1,sizeof hd);
	int n=read();
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
		addedge(v,u,w);
	}
	dfs(1,-1);
	for(int i=1;i<=n;++i)build(0,sum[i]);
    int ans=0;
    for(int i=1;i<=n;++i)
        ans=max(ans,query(0,sum[i]));
    write(ans);
	return 0;
}

