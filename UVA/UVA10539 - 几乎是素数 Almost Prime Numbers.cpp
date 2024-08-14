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
int dg[11415411],tot;
bool isPrime[11451411];
void init()
{
	for(int i=2;i<1e6;i++)
	{
		if(!isPrime[i])
		{
			for(int j=i*i;j<1e6;j+=i)isPrime[j]=1;
			for(int j=i*i;j<=1e12;j*=i)dg[++tot]=j;
		}
	}
}
signed main()
{
	init();
	sort(dg+1,dg+tot+1);
	int T=read();
	while(T--)
	{
		int l=read(),r=read();
		write((int)(lower_bound(dg+1,dg+tot+1,r)-dg)-(int)(lower_bound(dg+1,dg+tot+1,l)-dg));
		puts("");
	}
	return 0;
}

