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
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
int num[500010];
bool vis[500010];
inline void check()
{
    int n=read();
    for(int i=1;i<=n;++i)num[i]=read(),vis[i]=0;
    for(int i=1;i<=n;++i)
	{
        vis[num[i-1]]=1;
        int len=1;
        while(num[i]+len<=n&&num[i]-len>=1)
		{
            if(vis[num[i]+len]!=vis[num[i]-len])
			{
				puts("Y");
				return;
			}
            ++len;
        }
        if(i*n>=1e9)break;
    }
    puts("N");
    return;
}
int main()
{
	//file();
	int T=read();
	while(T--)check();
    return cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n',0;
}
