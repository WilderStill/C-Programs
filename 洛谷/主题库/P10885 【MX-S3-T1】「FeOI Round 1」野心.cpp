#include<bits/stdc++.h>
#define M 2000100
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
int a[M];
int main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n;++i)a[i]=read();
		if(n==1)
		{
			puts("0");
			continue;
		}
		if(n==2)
		{
			puts("1");
			continue;
		}
		int maxn=0,ans=0;
		for(int i=1;i<n;++i)
		{
			maxn=max(maxn,a[i]);
			if(maxn==i)++ans;
		}
		maxn=0;
		for(int i=n;i>1;--i)
		{
			maxn=max(maxn,a[i]);
			if(maxn==n-i+1)++ans;
		}
		bool even=0,odd=0;
		for(int i=1;i<=(n+1)/2;++i)
		{
			even|=a[i]&1;
			odd|=(a[i]&1)^1;
		}
		if((even&&!odd)||(!even&&odd))++ans;
		if(n&1)
		{
			bool even=0,odd=0;
			for(int i=n;i>=(n+1)/2;--i)
			{
				even|=a[i]&1;
				odd|=(a[i]&1)^1;
			}
			if((even&&!odd)||(!even&&odd))++ans;
		}
		if(n>3)
		{
			if(a[1]>a[2])swap(a[1],a[2]);
			if(a[n-1]>a[n])swap(a[n-1],a[n]);
			if((a[1]==1&&a[2]==n))++ans;
			if((a[n-1]==1&&a[n]==n))++ans;
		}
		printf("%d\n",ans);
	}
    return 0;
}

