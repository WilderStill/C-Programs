#include<bits/stdc++.h>
#define N 1100001
using namespace std;
void promote()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	return;
}
int n,num[N],q[N];
struct Accepted_Automation//AhoCorasickAutomaton
{
	struct TrieNode
	{
	    int son[27],val,fail,hd;
    }trie[N];
    struct Edge
	{
	    int hd,nxt;
    }edge[N];
    int rt,ncnt,ecnt,size[N];
	void insert(char *s,int l,int id)
	{
		int p=rt;
		for(int i=1;i<=l;i++)
		{
			int c=s[i]-'a'+1;
	    	if(!trie[p].son[c]) trie[p].son[c]=++ncnt;
	    	p=trie[p].son[c];
	    	size[p]++;
	    }
	    num[id]=p;
	    
	}
	void build()
	{
		int hd,tl;hd=tl=0;
	    for(int i=1;i<=27;i++)
	    	if(trie[0].son[i])
				q[++tl]=(trie[0].son[i]);
	    while(hd<tl)
		{
	    	int u=q[++hd];
	    	for(int i=1;i<=27;i++)
			{
		    	if(trie[u].son[i])
				{
		        	trie[trie[u].son[i]].fail=trie[trie[u].fail].son[i];// fail数组：同一字符可以匹配的其他位置
		        	q[++tl]=trie[u].son[i];
		    	}
				else
				{
					trie[u].son[i]=trie[trie[u].fail].son[i];
				}
	    	}
	  }
	}
	void query()
	{
		for(int i=ncnt;i>=1;i--) size[trie[q[i]].fail]+=size[q[i]];
		for(int i=1;i<=n;i++)printf("%d\n",size[num[i]]);
	}
}ac;
char s[N],t[N];
signed main()
{
	promote();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s+1;
		ac.insert(s,strlen(s+1),i);
	}
	ac.build();
	ac.query();
    return 0;
}
