#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	return x*f;
}
inline void write(int x)
{
    if(x<0)
	{
        putchar('-');
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
int n,dep,p[100010],ans[2][100010];
inline void dfs(int pos)
{
	++dep;
	if(dep>114514)return;
	if(pos>n)
	{
		if(!ans[1][0])
		{
			++ans[1][0];
			ans[1][ans[1][0]]=ans[0][ans[0][0]];
			--ans[0][0];
		}
		write(ans[0][0]),puts("");
		for(int i=1;i<=ans[0][0];++i)write(ans[0][i]),putchar(' ');
		puts("");
		write(ans[1][0]),puts("");
		for(int i=1;i<=ans[1][0];++i)write(ans[1][i]),putchar(' ');
		exit(0);
	}
	for(int i=0;i<=1;++i)
	{
		if(ans[i][0]>=2&&(p[pos]-ans[i][ans[i][0]]!=ans[i][ans[i][0]]-ans[i][ans[i][0]-1]))continue;
		ans[i][++ans[i][0]]=p[pos];
		dfs(pos+1),--ans[i][0];
	}
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)p[i]=read();
	sort(p+1,p+n+1);
	dfs(1);
	puts("-1");
    return 0;
}
