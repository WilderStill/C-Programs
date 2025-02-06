#include<bits/stdc++.h>
using namespace std;
constexpr int INF=0x3f3f3f3f;
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
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
	return;
}
int n,k,ans=-1;
char s[20];
int f[1010][410];
struct Accepted_Automation
{
	struct TrieNode
	{
	    int son[4],fail,p;
    }trie[200010];
    int ncnt;
	inline void insert(int l,char*s)
	{
		int tp=0;
		for(int i=0;i<l;++i)
		{
			int c=s[i]-'A';
	    	if(!trie[tp].son[c])trie[tp].son[c]=++ncnt;
	    	tp=trie[tp].son[c];
	    }
	    ++trie[tp].p;
	}
	inline void build()
	{
		queue<int>q;
	    for(int i=0;i<=2;++i)
	    	if(trie[0].son[i])
				q.push(trie[0].son[i]);
	    while(!q.empty())
		{
	    	int u=q.front();
	    	q.pop();
	    	for(int i=0;i<=2;++i)
			{
		    	if(trie[u].son[i])
				{
		        	trie[trie[u].son[i]].fail=trie[trie[u].fail].son[i];
					q.push(trie[u].son[i]);
		    	}
				else trie[u].son[i]=trie[trie[u].fail].son[i];
	    	}
	    	trie[u].p+=trie[trie[u].fail].p;
		}
	}
}ac;
int main()
{
    n=read(),k=read();
    for(int i=1;i<=n;++i)scanf("%s",s),ac.insert(strlen(s),s);
    ac.build();
    for(int i=0;i<=k;++i)
        for(int j=1;j<=ac.ncnt;++j)
            f[i][j]=-INF;
    for(int i=1;i<=k;++i)
        for(int j=0;j<=ac.ncnt;++j)
        	for(int c=0;c<=2;++c)
            	f[i][ac.trie[j].son[c]]=max(f[i][ac.trie[j].son[c]],f[i-1][j]+ac.trie[ac.trie[j].son[c]].p);
    for(int i=0;i<=ac.ncnt;++i)ans=max(ans,f[k][i]);
    write(ans);
    return 0;
}
