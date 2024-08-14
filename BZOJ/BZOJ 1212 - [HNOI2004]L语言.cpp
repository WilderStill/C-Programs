#include<bits/stdc++.h>
#define M 2000001
#define N 1000001
using namespace std;
int n,m,vis[M],f[M],idx[M];
struct Accepted_Automation//AhoCorasickAutomaton
{
	struct TrieNode
	{
	    int son[57],val,fail,hd;
    }trie[M];
    struct Edge
	{
	    int hd,nxt;
    }edge[M];
    int rt,ncnt,ecnt;
	void insert(char *s,int l)
	{
		int p=rt;
		for(register int i=0;i<l;++i)
		{
			register int c=s[i]-'a'+1;
	    	if(!trie[p].son[c])trie[p].son[c]=++ncnt;
	    	p=trie[p].son[c];
	    }
	    idx[p]=l;
		vis[p]=1; 
	}
	void build()
	{
		deque<int>q;
	    for(register int i=1;i<=26;++i)
	    	if(trie[0].son[i])
				q.push_back(trie[0].son[i]);
	    while(q.size())
		{
	    	register int u=q.front();
	    	q.pop_front();
	    	for(register int i=1;i<=26;++i)
			{
		    	if(trie[u].son[i])
				{
		        	trie[trie[u].son[i]].fail=trie[trie[u].fail].son[i];
					q.push_back(trie[u].son[i]);
		    	}
				else trie[u].son[i]=trie[trie[u].fail].son[i];
	    	}
	    }
	    for(int i=1;i<=ncnt;++i)
			for(int j=i;j;j=trie[j].fail)
				if(vis[j])
					f[i]|=(1<<idx[j]);
	}
	void query(char *s,int l)
	{
		int p=0,ans=0,stk=1;
		for(int i=1;i<=l;++i)
		{
			int c=s[i]-'a'+1;
			stk&=((1<<20)-1);
			stk<<=1;
			p=trie[p].son[c];
			if(stk&f[p])
			{
				ans=i;
				stk++;
			}
		}
		printf("%d\n",ans);
	}
}ac;
char s[N],t[N];
signed main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s);
		ac.insert(s,strlen(s));	
	}
	ac.build();
	for(int i=1;i<=m;++i)
	{
		scanf("%s",t+1);
		ac.query(t,strlen(t+1));
	}
    return 0;
}
