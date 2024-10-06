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
const int del=1e8+1;
int a[100010],b[100010],c[100010],tot;
char op[8];
int main()
{
    int n=read();
    while(n--)
	{
        scanf("%s",op);
        if(op[0]=='A')a[++tot]=read(),b[tot]=read(),c[tot]=read();
		if(op[0]=='D')a[read()]=del;
        if(op[0]=='Q')
		{
            int x=read(),cnt=0;
            for(int i=1;i<=tot;++i)
            {
            	while(a[i]==del)++i;
            	if(a[i]*x+b[i]>c[i])++cnt;
			}
        	write(cnt),puts("");
        }
    }
    return 0;
}

