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
inline void write(long long x)
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
int s[100010],t[100010];
long long ans;
int main()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)s[i]=read(),t[i]=read();
    for(int i=1;i<=n;++i)ans+=abs(t[i]-s[i]);
    s[++n]=m,t[n]=0;
    sort(s+1,s+n+1);
	sort(t+1,t+n+1);
    for(int i=1;i<=n;++i)ans+=abs(t[i]-s[i]);
    write(ans);
    return 0;
}

