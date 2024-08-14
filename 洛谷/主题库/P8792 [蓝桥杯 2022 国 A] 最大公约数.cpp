#include<bits/stdc++.h>
#define int long long
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
int a[110110100],is1=0,st_to_1=0x3f3f3f3f;
signed main()
{
	int n=read();
	for(int i=1;i<=n;++i)a[i]=read(),is1+=(a[i]==1);
	if(is1)
	{
		write(n-is1);
		exit(0);
	}
	for(int i=1;i<=n;++i)
	{
		int dg=a[i];
		for(int j=i+1;j<=n;++j)
		{
			dg=__gcd(dg,a[j]);
			if(j-i>st_to_1)break;
			if(dg==1)
			{
				st_to_1=j-i;
				break;
			}
		}
	}
	if(st_to_1==0x3f3f3f3f)write(-1);
	else write(n-1+st_to_1);
	return 0;
}

