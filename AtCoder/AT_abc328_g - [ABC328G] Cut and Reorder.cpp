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
int n,c,a[50],b[50],f[1<<22];
signed main()
{
	n=read(),c=read();
	for(int i=0;i<n;++i)a[i]=read();
	for(int i=0;i<n;++i)b[i]=read();
	memset(f,0x3f,sizeof f);
    f[0]=-c;
    for(int i=0;i<(1<<n);++i)
	{
        int s=__builtin_popcountll(i);
        for(int j=0;j<n;++j)
		{
            if(!(i>>j&1))
			{
                int tmp=i,sum=c;
                for(int l=j,k=s;!(i>>l&1)&&l<n;l++,k++)
				{
                    tmp|=1<<l;
                    sum+=abs(b[l]-a[k]);
                    f[tmp]=min(f[tmp],f[i]+sum);
                }
            }
        }
    }
	write(f[(1<<n)-1]);
	return 0;
}
