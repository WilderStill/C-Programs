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
ll sum[510],f[510][510];
int main()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)sum[i]=sum[i-1]+read();
    for(int i=1;i<=n;++i)
	{
    	for(int j=1;j<=m;++j)
		{
    		f[i][j]=f[i-1][j];
    		for(int k=1;k<=i;++k)f[i][j]=max(f[i][j],f[k-1][j-1]+sum[i]-sum[k-1]);
		}
    }
    write(f[n][m]);
    return 0;
}
