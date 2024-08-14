#include<bits/stdc++.h>
#define int long long
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
int ls;
int can[11000000],ans[11000000];
bool check(int x)
{
    while(x)
    {
        if(x%10==7)return 1;
        x/=10;
    }
    return 0;
}
void init()
{
    for(int i=1;i<=10000010;++i)
    {
        if(can[i])continue;
        if(check(i))
        {
            for(int j=i;j<=10000010;j+=i)can[j]=1;
            continue;
        }
        ans[ls]=i;
        ls=i;
    }
}
signed main()
{
    init();
    int T=read();
    while(T--)
    {
        int x=read();
        if(can[x])puts("-1");
        else write(ans[x]),puts("");
    }
    return 0;
}
