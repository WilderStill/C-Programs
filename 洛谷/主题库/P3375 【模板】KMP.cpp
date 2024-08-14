#include<bits/stdc++.h>
#define M 1145141
using namespace std;
char s[M],t[M];
int nxt[M],lens,lent;
int main()
{
	scanf("%s",s+1);
	scanf("%s",t+1);
	lens=strlen(s+1);
	lent=strlen(t+1);
	nxt[1]=0;
	for(int cur=1,now;cur<lent;cur++)
	{
		now=nxt[cur];
		while(now>0&&t[cur+1]!=t[now+1]) now=nxt[now];
		if(t[cur+1]==t[now+1]) nxt[cur+1]=now+1;
		else nxt[cur+1]=0;
	}
	for(int cur=1,now=0;cur<=lens;cur++)
	{
		while(now>0&&s[cur]!=t[now+1])now=nxt[now];
		if(s[cur]==t[now+1])now++;
		if(now==lent)
		{
			printf("%d\n",cur-lent+1);
		}
	}
	for(int i=1;i<=lent;i++)printf("%d ",nxt[i]);
	return 0;
}
