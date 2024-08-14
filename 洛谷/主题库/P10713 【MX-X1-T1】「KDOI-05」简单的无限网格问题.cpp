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
	int T=read();
	while(T--)
	{
		int n=read(),m=read();
		if(n==1&&m==1)write(0);
		else if(n-1&1&&m-1&1)
		{
			if(m==1||n==1)write(1);
			else write(3);
		}
		else if(n-1&1||m-1&1)write(2);
		else write(3);
		putchar('\n');
	}
	return 0;
}

