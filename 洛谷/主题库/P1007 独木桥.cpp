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
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
int num[100010];
int main()
{
    int l=read(),n=read(),mx=0,mn=0;
    if(!n)
    {
    	write(mn),putchar(' '),write(mx);
    	return 0;
	}
    for(int i=1;i<=n;++i)num[i]=read();
    sort(num+1,num+n+1);
    for(int i=1;i<=n;++i)mn=max(min(num[i],l-num[i]+1),mn);
    mx=max(l-num[1]+1,num[n]);
    write(mn),putchar(' '),write(mx);
    return 0;
}
