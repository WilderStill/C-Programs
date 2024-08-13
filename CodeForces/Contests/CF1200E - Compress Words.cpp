#include<bits/stdc++.h>
#define M 1145141
using namespace std;
int n,lenans,nxt[M];
char s[M],ans[M];
int main()
{ 
	scanf("%d",&n);
	for(int i=1,lens;i<=n;++i)
	{
		scanf("%s",s+1);
		lens=strlen(s+1);
		int minlen=min(lenans,lens),lent=lens;
		s[++lent]='#';
		nxt[0]=nxt[1]=0;
		for(int j=1;j<=minlen;++j)s[++lent]=ans[lenans-minlen+j];
		for(int cur=1,now;cur<lent;++cur)
		{
			now=nxt[cur];
			while(now>0&&s[now+1]!=s[cur+1])now=nxt[now];
			now+=(s[now+1]==s[cur+1]);
			nxt[cur+1]=now;
		}
		for(int j=nxt[lent]+1;j<=lens;++j)ans[++lenans]=s[j];
	}
	for(int i=1;i<=lenans;++i)putchar(ans[i]);
	return 0;
}
