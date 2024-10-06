#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	return x;
}
inline __int128 readl()
{
	__int128 x=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	return x;
}
inline void writel(__int128 x)
{
    if(x>9)writel(x/10);
    putchar(x%10+48);
}
struct node
{
	__int128 a,b;
	bool operator<(node t){return a*t.b>t.a*b;}
}num[3010];
int T,n,cl;
__int128 a,b,ans,suma,sumb;
inline void dfs(int pos,int ed)
{
	if(pos==ed+1)
	{
		__int128 syh=suma*sumb;
		if(syh>ans)ans=syh;
		return;
	}
	suma+=num[pos].a;
	dfs(pos+1,ed);
	suma-=num[pos].a;
	sumb+=num[pos].b;
	dfs(pos+1,ed);
	sumb-=num[pos].b;
}
inline void qsum(int k)
{
	suma=sumb=0;
	int l=max(1,k-cl),r=min(n,k+cl);
	for(int i=1;i<l;++i)suma+=num[i].a;
	for(int i=r+1;i<=n;++i)sumb+=num[i].b;
	dfs(l,r);
}
int main()
{
	T=read(),n=read(),a=readl(),b=readl();
	cl=5;
	while(T--)
	{
		ans=0;
		for(int i=1;i<=n;++i)num[i].a=readl(),num[i].b=readl();
		sort(num+1,num+n+1);
		for(int k=max(1,n/2-cl*10);k<=min(n,n/2+cl*10);++k)qsum(k);
		writel(ans);
		puts("");
	} 
    return 0;
}
