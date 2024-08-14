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
bool f[50005]; 
int main()
{
	int n=read(),m=read();
	while(m--)
	{
		int op=read(),x=read(),y;
		if(op==1)
		{
			int cnt=0,pos=1;
			for(int i=1;i<=x;++i)cnt+=f[i];
			while(cnt)
			{
				cnt+=f[pos+x];
				cnt-=f[pos++];
			}
			if(pos+x-1>n)
			{
				puts("0");
				continue;
			}
			write(pos);
			puts("");
			for(int i=0;i<x;++i)f[pos+i]=1;
		}
		else
		{
			y=read();
			for(int i=x;i<=x+y-1;++i)f[i]=0;
		}
	}
    return 0;
}

