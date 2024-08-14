#include<bits/stdc++.h>
#define M 1000001
#define N 1000001
using namespace std;
void promote()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	return;
}
int vis[M],ans[M],idx[M],top;
struct Accepted_Automation//AhoCorasickAutomaton
{
	struct TrieNode
	{
	    int son[27],val,fail,hd;
    }trie[M];
    struct Edge
	{
	    int hd,nxt;
    }edge[M];
    int rt,ncnt,ecnt;
	void insert(char *s,int l)
	{
		int p=rt;
		for(register int i=1;i<=l;i++)
		{
			register int c=s[i]-'a'+1;
	    	if(!trie[p].son[c]) trie[p].son[c]=++ncnt;//如果没有，就添加结点
	    	p=trie[p].son[c];
	    }
	    idx[p]=l; 
	}
	void build()
	{
		deque<int>q;
	    for(register int i=1;i<=26;i++)
	    	if(trie[0].son[i])
				q.push_back(trie[0].son[i]);
	    while(q.size())
		{
	    	register int u=q.front();
	    	q.pop_front();
	    	for(register int i=1;i<=26;i++)
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
	    for(register int i=1;i<=l;i++)
		{
	        int c=s[i]-'a'+1;
	        p=trie[p].son[c];
	        vis[++top]=p;
	        ans[top]=i;
	        if(idx[p])
			{
	            top-=idx[p];
	            p=!top?0:vis[top];
	        }
	    }
	}
}ac;
char s[N],t[N];
signed main()
{
	promote();
	cin>>t+1;
	cin>>s+1;
	ac.insert(s,strlen(s+1));
	ac.build();
	ac.query(t,strlen(t+1));
	for(register int i=1;i<=top;i++)cout<<t[ans[i]];
    return 0;
}
