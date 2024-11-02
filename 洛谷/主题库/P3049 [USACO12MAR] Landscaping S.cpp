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
inline void file()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
}
int d[110],f[2][2010],ans,dg;
signed main()
{
	//file();
	int n=read(),x=read(),y=read(),z=read();
	for(int i=1;i<=n;++i)d[i]=read()-read();
	memset(f,0x3f,sizeof f);
	f[0][1000]=0;
	for(int i=1;i<=n;++i)
	{
		memset(f[i&1],0x3f,sizeof f[i&1]);
		f[i&1][d[i]+1000]=f[(i-1)&1][1000];
		for(int j=0;j<=2000;++j)
		{
			if(d[i]>0)
			{
				for(int k=d[i];k>=0&&d[i]-k<=j;--k)
					f[i&1][j]=min(f[i&1][j],f[(i-1)&1][j-(d[i]-k)]+abs(j-1000-(d[i]-k))*z+k*y);
			}
			else
			{
				for(int k=-d[i];k>=0&&-d[i]-k<=j;--k)
					f[i&1][j]=min(f[i&1][j],f[(i-1)&1][j+(-d[i]-k)]+abs(j-1000+(-d[i]-k))*z+k*x);
			}
		}
	}
	write(f[n&1][1000]);
    return cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n',0;
}

