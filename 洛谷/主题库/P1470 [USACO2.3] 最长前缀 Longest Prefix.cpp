#include<bits/stdc++.h>
#define M 1000001
#define N 1000001
using namespace std;
int vis[M],idx[M];
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
		for(register int i=0;i<l;i++)
		{
			register int c=s[i]-'A'+1;
	    	if(!trie[p].son[c])trie[p].son[c]=++ncnt;
	    	p=trie[p].son[c];
	    }
	    idx[p]=l; 
	}
	void build()
	{
		deque<int>q;
	    for(register int i=1;i<=28;i++)
	    	if(trie[0].son[i])
				q.push_back(trie[0].son[i]);
	    while(q.size())
		{
	    	register int u=q.front();
	    	q.pop_front();
	    	for(register int i=1;i<=28;i++)
			{
		    	if(trie[u].son[i])
				{
		        	trie[trie[u].son[i]].fail=trie[trie[u].fail].son[i];
					q.push_back(trie[u].son[i]);
		    	}
				else trie[u].son[i]=trie[trie[u].fail].son[i];
	    	}
	  }
	}
	void query(char *s,int l)
	{
		vis[0]=1;
		int p=1;
		for(int i=1;i<=l;++i)
		{
			int c=s[i]-'A'+1;
			p=trie[p].son[c];
			for(int j=p;j&&!vis[i];j=trie[j].fail)
				if(idx[j])vis[i]|=vis[i-idx[j]];
		}
		for(int i=l;i>=0;--i)
			if(vis[i])
			{
				cout<<i;
				return;
			}
	}
}ac;
char s[N],t[N];
signed main()
{
	while(true)
	{
		cin>>s;
		if(!strcmp(s,"."))break;
		ac.insert(s,strlen(s));	
	}
	ac.build();
	char *p=t+1,c;
	while((c=getchar())!=EOF)
		if('A'<=c&&c<='Z')*p++=c;
	*p='\0';
	//cin>>t+1;
	ac.query(t,strlen(t+1));
    return 0;
}
