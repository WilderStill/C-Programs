#include<bits/stdc++.h>
#define int long long
#define M 500010
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
int n,m,d[M],s[M],t[M],del[M],sum[M],rt[M];
bool check(int x)
{
	memset(del,0,sizeof del);
	for(int i=1;i<=x;++i)
    {
        del[s[i]]+=d[i];
        del[t[i]+1]-=d[i]; 
    }
    for(int i=1;i<=n;++i)
    {
        sum[i]=sum[i-1]+del[i];
        if(sum[i]>rt[i])return 0;
    }
	return 1;
}
signed main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i)rt[i]=read();
	for(int i=1;i<=m;++i)d[i]=read(),s[i]=read(),t[i]=read();
	int l=1,r=m;
	if(check(r))
	{
		puts("0");
		return 0;
	}
	while(l<r)
	{
		int mid=(l+r)>>1;
        if(check(mid))l=mid+1;
        else r=mid;
	}
	puts("-1"),write(l);
	return 0;
}
