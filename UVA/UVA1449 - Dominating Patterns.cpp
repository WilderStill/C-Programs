#include<bits/stdc++.h>
#define M 1145141
#define N 11145
using namespace std;
struct AC
{
	int trie[N][63],id[N],fail[N],cnt[N],val[N],tot;
	queue<int>q;
	void init()
	{
		memset(fail,0,sizeof(fail));
		memset(trie,0,sizeof(trie));
		memset(val,0,sizeof(val));
		memset(cnt,0,sizeof(cnt));
		memset(id,0,sizeof(id));
		tot=0;
	}
	void insert(char *s,int l,int idx)
	{
		int p=0;
		for(int i=1;i<=l;i++)
		{
			int c;
			if(s[i]>='A'&&s[i]<='Z')c=s[i]-'A'+1;
			else if(s[i]>='a'&&s[i]<='z')c=s[i]-'a'+27;
			else if(s[i]>='0'&&s[i]<='9')c=s[i]-'0'+53;
	    	if(!trie[p][c]) trie[p][c]=++tot;//如果没有，就添加结点
	    	p=trie[p][c];
	    }
	    id[p]=idx;//结尾为p节点的字符串编号为idx 
	}

	void build()
	{
	    for(int i=1;i<=63;i++)
	    	if(trie[0][i])
				q.push(trie[0][i]);
	    while(!q.empty())
		{
	    	int u=q.front();
	    	q.pop();
	    	for(int i=1;i<=63;i++)
			{
		    	if(trie[u][i])
				{
		        	fail[trie[u][i]]=trie[fail[u]][i];// fail数组：同一字符可以匹配的其他位置
		        	q.push(trie[u][i]);
		    	}
				else
		        	trie[u][i]=trie[fail[u]][i];
	    	}
	  }
	}
	int query(char *s,int l)
	{
	    int p=0,res=-114514;
	    for(int i=1;i<=l;i++)
		{
			int c;
			if(s[i]>='A'&&s[i]<='Z')c=s[i]-'A'+1;
			else if(s[i]>='a'&&s[i]<='z')c=s[i]-'a'+27;
			else if(s[i]>='0'&&s[i]<='9')c=s[i]-'0'+53;
	    	p=trie[p][c];//转移
	    	for(int j=p;j;j=fail[j])val[j]++;
	  	}
	    for(int i=0;i<=tot;i++)
		{
			if(id[i])res=max(res,val[i]),cnt[id[i]]=val[i];	
		}
		return res;
	}
}acc;
int n,ans;
char s[N][N],t[M];
int main()
{
	while(~scanf("%d",&n))
	{	
		acc.init();
		if(n==0)return 0;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s[i]+1);
			acc.insert(s[i],strlen(s[i]+1),i);
		}
		scanf("%s",t+1);
		acc.build();
		ans=acc.query(t,strlen(t+1));
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
			if(acc.cnt[i]==ans)
				printf("%s\n",s[i]+1);
	}
    return 0;
}
