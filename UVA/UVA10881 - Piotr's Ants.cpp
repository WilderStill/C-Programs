#include<bits/stdc++.h>
using namespace std;
struct Ant
{
	int id,pos,dt;
	bool operator<(Ant b){return pos<b.pos;}
}pre[10010],suf[10010];
const char dt_name[3][10]={"L","Turning","R"};
int id[10010];
int main()
{
	//file();
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;++t)
	{
		int len,tim,n;
		scanf("%d%d%d",&len,&tim,&n);
		for(int i=1;i<=n;++i)
		{
			int pos,dt;char cmd;
			scanf("%d %c",&pos,&cmd);
			dt=(cmd=='L'?-1:1);
			pre[i]={i,pos,dt};
			suf[i]={0,pos+tim*dt,dt};
		}
		sort(pre+1,pre+n+1);
		for(int i=1;i<=n;++i)id[pre[i].id]=i;
		sort(suf+1,suf+n+1);
		for(int i=2;i<=n;++i)
			if(suf[i-1].pos==suf[i].pos)
				suf[i-1].dt=suf[i].dt=0;
		printf("Case #%d:\n",t);
		for(int i=1;i<=n;++i)
		{
			if(suf[id[i]].pos<0||suf[id[i]].pos>len)puts("Fell off");
			else printf("%d ",suf[id[i]].pos),puts(dt_name[suf[id[i]].dt+1]);
		}
		puts("");
	}
    return cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n',0;
}
