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
long long a[200010];
int main()
{
	long long n=read(),ans=0;
	for(long long i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+n+1);
	long long k=(n&1)?(n/2+1):(n/2);
	for(long long i=n;i>=1&&(n-i+1)<=k;--i)
	{
		if(a[i]>0)ans+=a[i];
		else break;
	}
	write(ans);
	return 0;
}

