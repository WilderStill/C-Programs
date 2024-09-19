#include<bits/stdc++.h>
#define ll long long
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
inline void write(ll x)
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
int num[80010];
int main()
{
	int n=read();
	for(int i=0;i<n;++i)num[i]=read();
	ll cnt=0;
	for(int i=n-1;~i;--i)
		for(int j=i+1;j<n;++j)
		{
			if(num[i]<=num[j])break;
			++cnt;
		}
	write(cnt);
	return 0;
}

