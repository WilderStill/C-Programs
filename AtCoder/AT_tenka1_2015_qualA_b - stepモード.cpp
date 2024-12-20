#include<bits/stdc++.h>
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
const int INF=0x3f3f3f3f;
inline int read_time()
{
	int hour=read()-21,minute=read(),second=read(),msecond=read();
	return (((hour*60+minute)*60+second)*1000+msecond);
} 
int st[1010],ed[1010];
int main()
{
	int n=read(),l=-INF,r=INF;
	for(int i=1;i<=n;++i)st[i]=read_time(),ed[i]=read_time();
	for(int i=1;i<=n;++i)
		if(ed[i]<=st[i])
			l=max(l,st[i]),r=min(r,ed[i]+1000);
	for(int i=1;i<=n;++i)
	{
		if(ed[i]<=st[i]||st[i]+1000<=l&&r<=ed[i])
		{
			write(ed[i]-st[i]+1000),puts("");
			continue;
		}
		if(ed[i]+1000<=l||st[i]>=r)
		{
			write(ed[i]-st[i]),puts("");
			continue;
		}
		puts("-1");
	}
	return 0;
}

