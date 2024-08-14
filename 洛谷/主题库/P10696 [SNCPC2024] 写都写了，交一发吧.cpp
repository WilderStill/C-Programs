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
int a[200010];
int main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n;++i)a[i]=read();
		sort(a+1,a+n+1);
		write(a[n]);
		putchar('\n');
	}
	return 0;
}

