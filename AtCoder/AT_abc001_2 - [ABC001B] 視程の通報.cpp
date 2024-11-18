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
int main()
{
	int n=read();
	if(n<100)
	{
		puts("00");
		return 0;
	}
	if(n<=5000)
	{
		int p=n/100;
		if(n<1000)putchar('0');
		write(p);
		puts("");
		return 0;
	}
	if(n<=30000)
	{
		int p=n/1000+50;
		write(p);
		puts("");
		return 0;
	}
	if(n<=70000)
	{
		int p=(n/1000-30)/5+80;
		write(p);
		puts("");
		return 0;
	}
	puts("89");
	return 0;
}
