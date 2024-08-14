#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
#define ql first
#define qr second
#define M 25014
#define N 5550489
using namespace std;
struct node
{
	int nxt[4];
	vector<pair<int,int>>v;
}trie[N];
int id,n,lim,ans,trie_cnt=1,idx[N],bit[N],f[N];
vector<int>v1[M],v2[M];
char s[M];
inline void insert(int l,int r)
{
	int x=1;
	for(register int i=l;i<=r;++i)
	{
		int ch=s[i]^'0';
		if(!trie[x].nxt[ch])trie[x].nxt[ch]=++trie_cnt;
		x=trie[x].nxt[ch];
		trie[x].v.push_back({l,i});
	}
}
inline void dfs(int x)
{
	int pre=id;
	for(auto p:trie[x].v)
	{
		idx[++id]=pre;
		v1[p.ql].push_back(id),v2[p.qr].push_back(id);
	}
	if(trie[x].nxt[0])dfs(trie[x].nxt[0]);
	if(trie[x].nxt[1])dfs(trie[x].nxt[1]);
}
inline void update(int x,int val){for(register int i=x;i<=id;i+=lowbit(i))bit[i]=max(bit[i],val);}
inline int query_max(int x)
{
	int res=0;
	for(register int i=x;i;i-=lowbit(i))res=max(res,bit[i]);
	return res;
}
int main()
{
	scanf("%d%s",&n,s+1);
	lim=sqrt(n*2);
	for(register int i=1;i<=n;++i)insert(i,min(i+lim-1,n));
	dfs(1);
	for(register int i=1;i<=n;++i)
	{
		for(auto x:v1[i])f[x]=query_max(idx[x])+1,ans=max(ans,f[x]);
		for(auto x:v2[i])update(x,f[x]);
	}
	printf("%d",ans);
	return 0;
}
