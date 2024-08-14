#include<bits/stdc++.h>
#define M 1145141
using namespace std;
struct AC
{
	int trie[M][63],e[M],fail[M],cnt;
	queue<int>q;
	void insert(char *s,int l)
	{
		int p=0;
		for(int i=1;i<=l;i++)
		{
			int c;
			if(s[i]>='A'&&s[i]<='Z')c=s[i]-'A'+1;
			else if(s[i]>='a'&&s[i]<='z')c=s[i]-'a'+27;
			else if(s[i]>='0'&&s[i]<='9')c=s[i]-'0'+53;
	    	if(!trie[p][c]) trie[p][c]=++cnt;//���û�У�����ӽ��
	    	p=trie[p][c];
	    }
	    e[p]++;//��βΪp�ڵ���ַ����ĸ���
	}

	void build()
	{
	    for(int i=1;i<=63;i++)
	    	if(trie[0][i])
				q.push(trie[0][i]);
	    while(q.size())
		{
	    	int u=q.front();
	    	q.pop();
	    	for (int i = 1; i <=63; i++)
			{
		      	if (trie[u][i])
				{
		        	fail[trie[u][i]]=trie[fail[u]][i];// fail���飺ͬһ�ַ�����ƥ�������λ��
		        	q.push(trie[u][i]);
		      	}
				else
		        	trie[u][i] =trie[fail[u]][i];
	    	}
	  }
	}
	
	int query(char *s,int l)
	{
	    int p=0,res=0;
	    for(int i=1;i<=l;i++)
		{
			int c;
			if(s[i]>='A'&&s[i]<='Z')c=s[i]-'A'+1;
			else if(s[i]>='a'&&s[i]<='z')c=s[i]-'a'+27;
			else if(s[i]>='0'&&s[i]<='9')c=s[i]-'0'+53;
	    	p=trie[p][c];//ת��
	    	for (int j=p;j&&e[j]!=-1;j=fail[j])res+=e[j],e[j]=-1;
	  }
	  return res;
	}
}acc;
int n;
char s[M],t[M];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		acc.insert(s,strlen(s+1));
	}
	scanf("%s",t+1);
	acc.build();
	printf("%d",acc.query(t,strlen(t+1)));
  return 0;
}
