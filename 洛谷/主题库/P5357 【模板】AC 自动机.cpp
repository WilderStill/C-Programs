#include<bits/stdc++.h>
#define int long long
#define M 245141
#define N 2114514
using namespace std;
void promote()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	return;
}
int ans[M],n;
struct Accepted_Automation//AhoCorasickAutomaton
{
	struct TrieNode
	{
	    int son[30],val,fail,hd;
	    deque<int>idx;
    }trie[M];
    struct Edge
	{
	    int hd,nxt;
    }edge[M];
    int rt,ncnt,ecnt;
	void insert(char *s,int l,int id)
	{
		int p=rt;
		for(int i=1;i<=l;i++)
		{
			int c=s[i]-'a'+1;
	    	if(!trie[p].son[c]) trie[p].son[c]=++ncnt;//如果没有，就添加结点
	    	p=trie[p].son[c];
	    }
	    trie[p].idx.push_back(id);//结尾为p节点的字符串编号为idx 
	}
	void build()
	{
		deque<int>q;
	    for(int i=1;i<=27;i++)
	    	if(trie[0].son[i])
				q.push_back(trie[0].son[i]);
	    while(!q.empty())
		{
	    	int u=q.front();
	    	q.pop_front();
	    	for(int i=1;i<=27;i++)
			{
		    	if(trie[u].son[i])
				{
		        	trie[trie[u].son[i]].fail=trie[trie[u].fail].son[i];// fail数组：同一字符可以匹配的其他位置
		        	q.push_back(trie[u].son[i]);
		    	}
				else
				{
					trie[u].son[i]=trie[trie[u].fail].son[i];
				}
	    	}
	  }
	}
	void query(char *s,int l)
	{
	    int p=0;
	    for(int i=1;i<=l;i++)
		{
			int c=s[i]-'a'+1;
	    	p=trie[p].son[c];//转移
	    	trie[p].val++;
	  	}
		return;
	}
	void add(int tl,int hd)
	{
	    edge[++ecnt].hd=hd;
	    edge[ecnt].nxt=trie[tl].hd;
	    trie[tl].hd=ecnt;
	    return;
    }
    void dfs(int u)
	{
	    for(int e=trie[u].hd;e;e=edge[e].nxt)
		{
	    	int v=edge[e].hd;
	    	dfs(v);
	    	trie[u].val+=trie[v].val;
	    }
	    for(auto i:trie[u].idx) ans[i]+=trie[u].val;
	    return;
	}
	void failT()
	{
	    for(int u=1;u<=ncnt;u++) add(trie[u].fail,u);
	    dfs(rt);
	    return;
	}
}ac;
char s[N];
signed main()
{
	promote();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s+1;ac.insert(s,strlen(s+1),i);
	}
	cin>>s+1;
	ac.build();
	ac.query(s,strlen(s+1));
	ac.failT();
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<endl;
	}
    return 0;
}
