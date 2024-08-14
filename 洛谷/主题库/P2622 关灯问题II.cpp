#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define M 114
using namespace std;
int n,m,op[M],cl[M],f[1<<20];
bool vis[1<<20];
queue<int>q;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		for(int j=1,x;j<=n;++j)
		{
			scanf("%d",&x);
			if(x==1)op[i]|=(1<<j-1);
			if(x==-1)cl[i]|=(1<<j-1);
		}
	memset(f,INF,sizeof(f));
	f[0]=0;
	q.push(0);
	while(q.size())
	{
		int top=q.front();
		q.pop();
		vis[top]=0;
		for(int i=1;i<=m;++i)
		{
			int stktop=(top|op[i])&(~cl[i]);
			if(f[stktop]>f[top]+1)
			{
				f[stktop]=f[top]+1;
				if(!vis[stktop])
				{
					vis[stktop]=1;
					q.push(stktop);
				}
			}
		}
	}
	if(f[(1<<n)-1]==INF)puts("-1");
	else printf("%d",f[(1<<n)-1]);
	return 0;
}
