#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define lowbit(x) ((x)&(-x))
#define N 1114514
using namespace std;
int n,q,tim,dfn[N],low[N],idx[N];
bool vis[N];
char s[N];
vector<int>edge[N];
struct BinaryIndexedTree
{
    int bit[N],n;
	BinaryIndexedTree(){memset(bit,0,sizeof bit);}
    void modify(int x,int v)
	{
		for(int i=x;i<=n;i+=lowbit(i))bit[i]+=v;
	}
    int query(int x)
	{
		int res=0;
		for(int i=x;i>0;i-=lowbit(i))res+=bit[i];
		return res;
	}
    void modify_lrv(int l,int r,int v)
	{
		modify(l,v);
		modify(r+1,-v);
	}
}Bit;
struct AhoCorasickAutomaton
{
	struct node
	{
		int nxt,ed,son[27];
	}trie[N];
	int ncnt=0,rt=0;
	void insert(char s[],int l,int id)
	{
		int p=0;
		for(int i=1;i<=l;++i)
		{
			int c=s[i]-'a'+1;
			if(!trie[p].son[c])trie[p].son[c]=++ncnt;
			p=trie[p].son[c];
		}
		idx[id]=p;
	}
	void build()
	{
		deque<int>q;
		for(int i=1;i<=26;++i)
		{
			if(trie[0].son[i])
			{
				edge[0].emplace_back(trie[0].son[i]);
				trie[trie[0].son[i]].nxt=0;
				q.emplace_back(trie[0].son[i]);
			}
		}
		while(q.size())
		{
			int top=q.front();
			q.pop_front();
			for(int i=1;i<=26;++i)
			{
				if(trie[top].son[i])
				{
					trie[trie[top].son[i]].nxt=trie[trie[top].nxt].son[i];
					edge[trie[trie[top].son[i]].nxt].emplace_back(trie[top].son[i]);
					q.push_back(trie[top].son[i]);
				}
				else trie[top].son[i]=trie[trie[top].nxt].son[i];
			}
		}
	}
	int query(char s[],int l)
	{
		int p=0,res=0;
		for(int i=1;i<=l;++i)
		{
			int c=s[i]-'a'+1;
			p=trie[p].son[c];
			res+=Bit.query(dfn[p]);
		}
		return res;
	}
}ac;
void dfs(int u)
{
	dfn[u]=++tim;
	for(auto v:edge[u])dfs(v);
	low[u]=tim;
}
signed main()
{
	scanf("%d%d",&q,&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		ac.insert(s,strlen(s+1),i);
	}
	ac.build();
	dfs(0);
	Bit.n=tim;
	for(int i=1;i<=n;++i)Bit.modify_lrv(dfn[idx[i]],low[idx[i]],1);
	for(int i=1,x;i<=q;++i)
	{
		char op=getchar();
		while(op!='-'&&op!='+'&&op!='?')op=getchar();
		switch(op)
		{
			case '?':
			{
				scanf("%s",s+1);
				printf("%d\n",ac.query(s,strlen(s+1)));
				break;
			}
			case '-':
			{
				scanf("%d",&x);
				if(!vis[x])
				{
					vis[x]=1;
					Bit.modify_lrv(dfn[idx[x]],low[idx[x]],-1);
				}
				break;
			}
			case '+':
			{
				scanf("%d",&x);
				if(vis[x]) 
				{
					vis[x]=0;
					Bit.modify_lrv(dfn[idx[x]],low[idx[x]],1);
				}
				break;
			}
		}
	}
    return 0;
}
