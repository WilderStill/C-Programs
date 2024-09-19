#include<bits/stdc++.h>
#define M 100010
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
int h[M],ans;
int main()
{
	int n=read(),x=read()<<1;
	for(int i=1;i<n;++i)h[i]=read();
	for(int i=1,j=0,sum=0;i<n;++i)
	{
		while(j<n&&sum<x)sum+=h[++j];
		ans=max(ans,j-i+1);
		sum-=h[i];
	}
	write(ans);
	return 0;
}

