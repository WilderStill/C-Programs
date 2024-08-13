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
int qpow(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1)res=res*x;
		x=x*x;
		y>>=1;
	}
	return res;
}
signed main()
{
	int n=read();
	write(qpow(2,n+1)-2);
	return 0;
}

