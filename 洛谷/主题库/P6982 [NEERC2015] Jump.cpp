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
inline void file()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}
mt19937 dg(time(0));
bool s[10010],ans[10010];
int main()
{
	//file();
	int n=read(),k;
	for(int i=1;i<500;++i)
    {
        for(int j=1;j<=n;++j)s[j]=dg()&1,write(s[j]);
        puts("");
        fflush(stdout);
        k=read();
        if(k==n)return 0;
        if(k==n/2)break;
    }
    ans[0]=s[0],s[1]^=1;
    for(int i=1;i<=n;++i)
    {
        s[i]^=1;
		for(int j=1;j<=n;++j)write(s[j]);
        puts("");
        fflush(stdout);
        k=read();
        if(k==n)return 0;
		s[i]^=1;
        ans[i]=s[i]^(k==n/2);
    }
    for(int i=1;i<=n;++i)write(ans[i]);
    puts("");
    fflush(stdout);
    k=read();
    if(k==n)return 0;
    for(int i=1;i<=n;++i)write(ans[i]^1);
    puts("");
    fflush(stdout);
    return cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n',0;
}
