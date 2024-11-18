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
const ll INF=0x3f3f3f3f;
ll r[202],sumri[202],sumr[202],f[202][202][10];
int main()
{
	ll n=read(),K=read(),ans=INF;
	for(int i=1;i<=n;++i)r[i]=r[i+n]=read();
	for(int i=1;i<=2*n;++i)sumr[i]=sumr[i-1]+r[i],sumri[i]=sumri[i-1]+r[i]*i;
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;++i)
	{
		f[i][i+n][0]=0;
		for(int k=1;k<=K;++k)
		{
			for(int j=n+i-1;j>=i;--j) 
				for(int m=j+1;m<=n+i;++m)
					if(f[i][m][k-1]<INF)
						f[i][j][k]=min(f[i][j][k],f[i][m][k-1]+sumri[m-1]-sumri[j]-j*(sumr[m-1]-sumr[j]));
			ans=min(ans,f[i][i][k]);
		}
	}
	write(ans);
	return 0;
}
