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
const int mod=10007;
int num[100010],col[100010],kd[100010][2],sum[100010][2];
int main()
{
	int n=read(),m=read(),ans=0;
	for(int i=1;i<=n;++i)num[i]=read();
	for(int i=1;i<=n;++i)
	{
		col[i]=read();
		++kd[col[i]][i&1];
		(sum[col[i]][i&1]+=num[i])%=mod;
	}
	for(int i=1;i<=n;++i)(ans+=i*((kd[col[i]][i&1]-2)*num[i]%mod+sum[col[i]][i&1]))%=mod;
	write(ans);
    return cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n',0;
}

