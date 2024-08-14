#include<bits/stdc++.h>
#define M 3114514
using namespace std;
struct trie_tree
{
	int nxt[M][63],cnt;
	int is_in[M];//该结点结尾的字符串存在个数
	inline void insert(char *s,int l)//插入字符串
	{
		int p=0;
		for(int i=0;i<l;++i)
		{
			int c;
			if(s[i]>='A'&&s[i]<='Z')c=s[i]-'A'+1;
			else if(s[i]>='a'&&s[i]<='z')c=s[i]-'a'+27;
			else if(s[i]>='0'&&s[i]<='9')c=s[i]-'0'+53;
			if(!nxt[p][c])nxt[p][c]=++cnt;  // 如果没有，就添加结点
			p=nxt[p][c];
			is_in[p]++;
		}
	}
	inline int find(char *s,int l)//查找字符串
	{
		int p=0;
		for(int i=0;i<l;++i)
		{
			int c;
			if(s[i]>='A'&&s[i]<='Z')c=s[i]-'A'+1;
			else if(s[i]>='a'&&s[i]<='z')c=s[i]-'a'+27;
			else if(s[i]>='0'&&s[i]<='9')c=s[i]-'0'+53;
			if(!nxt[p][c])return 0;
			p=nxt[p][c];
		}
		return is_in[p];
	}
}tmp;
int T,n,q,ans;
char s[M],t[M];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		for(register int i=0;i<=tmp.cnt;++i)
            for(register int j=0;j<=62;++j)
                tmp.nxt[i][j]=0;
		for(register int i=0;i<=tmp.cnt;++i)tmp.is_in[i]=0;
		tmp.cnt=0;
		scanf("%d%d",&n,&q);
		for(register int i=1;i<=n;++i)
		{
			scanf("%s",s);
			tmp.insert(s,strlen(s));
		}
		for(register int i=1;i<=q;++i)
		{
			scanf("%s",t);
			printf("%d\n",tmp.find(t,strlen(t)));
		}
	}
	return 0;
}
