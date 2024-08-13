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
signed main()
{
	int xl=read(),yl=read(),xr=read(),yr=read(),dx=xr-xl+1,dy=yr-yl+1;
	write(((dx+1)/2)*((dy+1)/2)+((dx-1)/2)*((dy-1)/2));
	return 0;
}

