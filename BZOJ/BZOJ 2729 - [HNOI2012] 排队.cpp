#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p=10000000000;
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
int ans[10086],len=1;
void syh(int val)
{
    int sb_2=0,kb;
    for(int i=1;i<=len;++i)
    {
        kb=ans[i]*val;
        ans[i]=kb%p+sb_2;
        sb_2=kb/p;
    }
    if(sb_2)ans[++len]=sb_2;
}
signed main()
{
	int n=read(),m=read();
    ans[1]=1;
    syh(n+1);
	syh(n*(n+3)+2*m);
    for(int i=1;i<=n;++i)syh(i);
    for(int i=n-m+4;i<=n+2;++i)syh(i);
    printf("%lld",ans[len]);
    while(--len)printf("%010lld",ans[len]);
	return 0;
}

