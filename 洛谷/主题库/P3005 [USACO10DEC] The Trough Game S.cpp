#include<bits/stdc++.h>
using namespace std;
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
int n,m,sum[111];
bool isans,tp[111],ans[111];
char q[111][111];
inline void dfs(int pos)
{
	if(pos==n+1)
	{
		bool fg=1;
		for(int i=1;i<=m;++i)
		{
			int tk=0;
			for(int j=1;j<=n;++j)if(q[i][j]&15)tk+=tp[j];
			if(tk^sum[i]){fg=0;break;} 
		}
		if(fg)
		{
			if(isans)
			{
				puts("NOT UNIQUE");
				exit(0);
			}
			isans=1;
			memcpy(ans,tp,sizeof ans);
		} 
		return;
	}
	dfs(pos+1);
	tp[pos]=1;
	dfs(pos+1);
	tp[pos]=0;
	return;
} 
int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;++i)scanf("%s",q[i]+1),sum[i]=read();
	dfs(1);
	if(!isans)
	{
		puts("IMPOSSIBLE");
		return 0;
	}
	for(int i=1;i<=n;++i)write(ans[i]);
	return 0;
}
