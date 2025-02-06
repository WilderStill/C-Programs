#include<bits/stdc++.h>
#define M 3000100
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
char s[M];
inline int readstr()
{
	int cnt=0;
	char ch=getchar();
	while(ch!='0'&&ch!='1')ch=getchar();
	while(ch=='0'||ch=='1')
	{
		s[cnt++]=ch;
		ch=getchar();
	}
	return cnt;
}
struct Accepted_Automation
{
	struct TrieNode
	{
	    int son[2],fail;
	    bool sk;
    }trie[M];
    bool is[M],vis[M];
    int ncnt;
	inline void insert(int l,int id)
	{
		int p=0;
		for(int i=0;i<l;++i)
		{
			int c=s[i]-'0';
	    	if(!trie[p].son[c])trie[p].son[c]=++ncnt;
	    	p=trie[p].son[c];
	    }
	    trie[p].sk=1;
	}
	inline void build()
	{
		deque<int>q;
	    for(int i=0;i<=1;++i)
	    	if(trie[0].son[i])
				q.push_back(trie[0].son[i]);
	    while(!q.empty())
		{
	    	int u=q.front();
	    	q.pop_front();
	    	for(int i=0;i<=1;++i)
			{
		    	if(trie[u].son[i])
				{
		        	q.push_back(trie[u].son[i]);
                    int fl=trie[u].fail;
                    while(fl&&!trie[fl].son[i])fl=trie[fl].fail;
                    if(!trie[fl].son[i])trie[trie[u].son[i]].fail=0;
                    else
					{
                        trie[trie[u].son[i]].fail=trie[fl].son[i];
                        if(trie[trie[fl].son[i]].sk)trie[trie[u].son[i]].sk=1;
                    }
		    	}
				else trie[u].son[i]=trie[trie[u].fail].son[i];
	    	}
	  }
	}
    inline void dfs(int x)
	{
	    is[x]=1;
    	for(int i=0;i<=1;++i)
	        if(is[trie[x].son[i]])
			{
	            puts("TAK");
	            exit(0);
	        }
			else if(!trie[trie[x].son[i]].sk&&!vis[trie[x].son[i]])
			{
	            vis[trie[x].son[i]]=1;
	            dfs(trie[x].son[i]); 
	        }
    	is[x]=0;
	}
}ac;
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)
	{
		int len=readstr();
		ac.insert(len,i);
	}
	ac.build();
	ac.dfs(0);
	puts("NIE");
    return 0;
}
