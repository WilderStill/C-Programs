#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read()
{
    ll x=0,f=1;
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
inline void file()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}
ll f[1000010],sum[1000010],pos[1000010],num[1000010];
int main()
{
	//file();
	int T=read();
	while(T--)
	{
		int n=read();
		memset(f,0,sizeof f);
		memset(sum,0,sizeof sum);
		memset(pos,0,sizeof pos);
		for(int i=1;i<=n;++i)num[i]=read();
		for(int i=2;i<=n;++i)
		{
			if(num[i]==num[i-1])sum[i]=sum[i-1]+num[i];
			else sum[i]=sum[i-1];
		}
		for(int i=1;i<=n;++i)
		{
			f[i]=f[i-1];
			if(pos[num[i]])f[i]=max(f[i],f[pos[num[i]]+1]+num[i]+sum[i]-sum[pos[num[i]]+1]);
			pos[num[i]]=i;
		}
		write(f[n]);
		puts("");
	}
    return cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n',0;
}

