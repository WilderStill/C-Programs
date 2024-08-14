#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	return x*f;
}
inline ll readl()
{
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	return x*f;
}
inline void write(ll x)
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
ll num[5010],f[5010];
int main()
{
	memset(f,INF,sizeof f);
	int n=read(),b=read(),a=read();
	for(int i=1;i<=n;++i)num[i]=readl();
	f[0]=0;
	num[n+1]=n+1;
	for(int i=1;i<=n+1;++i)
	{
		int r=0,l=0;
		for(int j=i-1;~j;--j)
		{
			if(num[j]<num[i])f[i]=min(f[i],f[j]+1ll*b*r+1ll*a*l),++l;
			if(num[j]>num[i])++r;
		}
	}
	write(f[n+1]);
	return 0;
}
