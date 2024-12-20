#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))
	{
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch))
	{
        x=(x<<1)+(x<<3)+(ch^48);
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
    putchar(x%10+48);
    return;
}
int dis[201000];
struct node
{
	int from,to,val;
}edge[201000];
signed main()
{
	int n=read(),m=read(),s=1;
	for(int i=1;i<=m;++i)edge[i]={read(),read(),read()};
	for(int i=1;i<=n;++i)dis[i]=INF;
	dis[s]=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(dis[edge[j].to]>dis[edge[j].from]+edge[j].val)dis[edge[j].to]=dis[edge[j].from]+edge[j].val;
	for(int i=1;i<=n;++i)write(dis[i]==INF?-1:dis[i]),putchar(' ');
	return 0;
}
