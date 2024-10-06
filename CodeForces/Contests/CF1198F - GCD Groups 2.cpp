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
int n,num[100010],id[100010],ans[100010]; 
int main()
{
	n=read();
	for(int i=1;i<=n;++i)num[i]=read(),id[i]=i;
	while(1.0*clock()/CLOCKS_PER_SEC<=0.47)
	{
		random_shuffle(id+1,id+n+1);
		int gcd1=0,gcd2=0;
		for(int i=1;i<=n;++i)
		{
			int gcd=__gcd(gcd1,num[id[i]]);
			if(gcd!=gcd1)
			{
				gcd1=gcd;
				ans[id[i]]=1;
			}
			else
			{
				gcd2=__gcd(gcd2,num[id[i]]);
				ans[id[i]]=2;
			}
		}
		if(gcd1==1&&gcd2==1)
		{
			puts("YES");
			for(int i=1;i<=n;++i)write(ans[i]),putchar(' ');
			return 0;
		}
	}
	puts("NO");
    return 0;
}

