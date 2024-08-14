#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
    long long x=0,f=1;
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
inline void write(long long x)
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
const long long p=1000000007;
int main()
{
	long long n=read(),m=read(),k=read(),x_0=read(),y_0=read(),ans=0;
	for(long long i=1;i<=k;++i)
	{
		long long x=read(),y=read(),dx,dy,t;
		if(x==x_0)
		{
			dy=y>y_0?m-y+1:y;
			t=(m-dy-1);
			dy%=p;
			t%=p;
            ans=(ans+dy*((m+n-2)%p)+dy*t)%p;
		}
		else if(y==y_0)
		{
			dx=x>x_0?n-x+1:x;
			t=(n-dx-1);
			dx%=p;
			t%=p;
            ans=(ans+dx*((m+n-2)%p)+dx*t)%p;
		}
		else
		{
			dx=x>x_0?n-x+1:x;dx%=p;
			dy=y>y_0?m-y+1:y;dy%=p;
			ans=(ans+dx+dy)%p;
		}
	}
	write(ans);
	return 0;
}
