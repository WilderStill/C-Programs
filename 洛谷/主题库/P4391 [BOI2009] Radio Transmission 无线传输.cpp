#include<bits/stdc++.h>
#define M 1145141
using namespace std;
char t[M];
int nxt[M],lens,lent;
int main()
{
	scanf("%d",&lent);
	scanf("%s",t+1);
	nxt[1]=0;
	for(int cur=1,now;cur<lent;cur++)
	{
		now=nxt[cur];
		while(now>0&&t[cur+1]!=t[now+1]) now=nxt[now];
		if(t[cur+1]==t[now+1]) nxt[cur+1]=now+1;
		else nxt[cur+1]=0;
	}
	printf("%d ",lent-nxt[lent]);
	return 0;
}
