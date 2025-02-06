#include<bits/stdc++.h>
#define M 100100
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
inline void write(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
	return;
}
char s[M];
inline int readstr()
{
	int cnt=0;
	char ch=getchar();
	while(ch!='B'&&ch!='P'&&!islower(ch))ch=getchar();
	while(ch=='B'||ch=='P'||islower(ch))
	{
		s[cnt++]=ch;
		ch=getchar();
	}
	return cnt;
}
struct Accepted_Automation
{
	struct TrieNode{int son[28],fail,fa;}trie[M];
    int hd[M],dis[M],dfn[M],low[M];
    struct Edge{int to,nxt;}edge[M<<1];
    int rt,ncnt,wcnt,ecnt,tim;
	inline int insert(int p,char s)
	{
		int c=s-'a'+1;
		if(trie[p].son[c])return trie[p].son[c];
        trie[p].son[c]=++ncnt;
		trie[ncnt].fa=p;
		return ncnt;
	}
	inline int back(int p){return trie[p].fa;}
    inline void ed(int p){dis[++wcnt]=p;}
	inline void build()
	{
		queue<int>q;
	    for(int i=1;i<=27;++i)if(trie[0].son[i])q.push(trie[0].son[i]);
	    while(!q.empty())
		{
	    	int u=q.front();q.pop();
	    	for(int i=1;i<=27;++i)
			{
		    	if(trie[u].son[i])trie[trie[u].son[i]].fail=trie[trie[u].fail].son[i],q.push(trie[u].son[i]);
				else trie[u].son[i]=trie[trie[u].fail].son[i];
	    	}
		}
		for(int u=1;u<=ncnt;++u)addedge(u,trie[u].fail),addedge(trie[u].fail,u);
	    dfs(rt,0);
	}
	inline void addedge(int u,int v){edge[++ecnt]={v,hd[u]};hd[u]=ecnt;}
    inline void dfs(int u,int pa)
	{
		dfn[u]=++tim;
	    for(int i=hd[u];i;i=edge[i].nxt)
		{
			int v=edge[i].to;
			if(v^pa)dfs(v,u);
		}
		low[u]=++tim;
	}
}ac;
struct Fenwick_Tree
{
	int tr[M],n;
	inline int lowbit(int x){return x&(-x);}
	inline void add(int x,int v){for(int i=x;i<=n;i+=lowbit(i))tr[i]+=v;}
	inline int query(int x){int res=0;for(int i=x;i;i-=lowbit(i))res+=tr[i];return res;}
}bit;
struct Query{int v,id;};
vector<Query>q[M];
int ans[M];
int main()
{
	int len=readstr();
	for(int i=0,p=0;i<len;++i)
	{
		if(s[i]=='B'){p=ac.back(p);continue;}
        if(s[i]=='P'){ac.ed(p);continue;}
        p=ac.insert(p,s[i]);
	}
	int m=read();
    for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		q[v].emplace_back((Query){u,i});
	}
	ac.build();bit.n=ac.tim;
	for(int i=0,cnt=0,p=0;i<len;++i)
    {
        if(s[i]=='P')
        {
            for(auto dg:q[++cnt])ans[dg.id]=bit.query(ac.low[ac.dis[dg.v]])-bit.query(ac.dfn[ac.dis[dg.v]]-1);
            continue;
        }
        if(s[i]=='B')
		{
			bit.add(ac.dfn[p],-1),p=ac.back(p);
			continue;
		}
        p=ac.trie[p].son[s[i]-'a'+1];
        bit.add(ac.dfn[p],1);
    }
    for(int i=1;i<=m;++i)write(ans[i]),puts("");
    return 0;
}
