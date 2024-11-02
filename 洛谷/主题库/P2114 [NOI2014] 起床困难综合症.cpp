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
struct node
{
	char op;
	int tp;
}f[1000010];
int n,m;
inline int calc(int val)
{
    for(int i=1;i<=n;++i)
    {
        if(f[i].op=='A')val&=f[i].tp;
        if(f[i].op=='O')val|=f[i].tp;
        if(f[i].op=='X')val^=f[i].tp;
    }
    return val;
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        char s[2];
        scanf("%s",s);
		f[i].op=s[0];
        f[i].tp=read();
    }
    int ans=0;
    for(int i=31;~i;--i)
    {
        if(ans+(1<<i)>m)continue;
        if(calc(ans)<calc(ans+(1<<i)))ans+=(1<<i);
    }
    write(calc(ans));
    return 0;
}


