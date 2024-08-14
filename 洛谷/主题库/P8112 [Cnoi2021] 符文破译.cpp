#include<bits/stdc++.h>
#define M 11145141
using namespace std;
int lent,lens,nxt[M],ans;
char t[M],s[M];
int main()
{
	scanf("%d%d%s%s",&lent,&lens,t+1,s+1);
	for(int cur=2,now=0;cur<=lent;++cur)
	{
		while(now>0&&(t[cur]!=t[now+1]))now=nxt[now];
		if(t[cur]==t[now+1])++now;
		nxt[cur]=now;
	}
	for(int cur=1,now=0,tmp=0;cur<=lens;++cur)
	{
		while(now>0&&(now==lent||s[cur]!=t[now+1]))now=nxt[now];
		if(s[cur]==t[now+1])++now;
		if(!now)
		{
			puts("Fake");
			return 0;
		}
		if(cur>=now+tmp)
		{
			ans++;
			tmp=cur;
		}
	}
	printf("%d",ans);
	return 0;
}
