#include<bits/stdc++.h>
#define ll long long
#define M 1000010
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
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
int n,m,blen,num[M],sum[M],pre[5010][5010],suf[5010][5010];
const int mod=1000000007; 
inline void modify(int x,int y,int z)
{
	if(x>=blen)
	for(int i=y;i<=n;i+=x)
	{
		num[i]=(num[i]+z)%mod;
		int blo=(i-1)/blen+1;
		sum[blo]=(sum[blo]+z)%mod;
	}
	else
	{
		for(int i=y;i<=x;++i)pre[x][i]=(pre[x][i]+z)%mod;
		for(int i=1;i<=y;++i)suf[x][i]=(suf[x][i]+z)%mod;
	}
}
inline int query(int pl,int pr)
{
	int l=(pl-1)/blen+1,r=(pr-1)/blen+1;
	ll res=0;
	if(l==r)for(int i=pl;i<=pr;++i)res+=num[i];
	else
	{
		for(int i=pl;i<=l*blen;++i)res+=num[i];
		for(int i=l+1;i<r;++i)res+=sum[i];
		for(int i=(r-1)*blen+1;i<=pr;++i)res+=num[i];
	}
	for(int i=1;i<blen;++i)
	{
		int tl=(pl-1)/i+1,tr=(pr-1)/i+1,t=tr-tl-1;
		if(tl==tr)(res+=(pre[i][(pr-1)%i+1]-pre[i][(pl-1)%i]))%=mod;
		else (res+=(1ll*pre[i][i]*t+pre[i][(pr-1)%i+1]+suf[i][(pl-1)%i+1]))%=mod;
	}
	return (res+mod)%mod;
}
int main()
{
	n=read(),m=read();
	blen=sqrt(n)/3;
	if(!blen)blen=1;
	for(int i=1;i<=n;++i)
	{
		num[i]=read();
		int blo=(i-1)/blen+1;
		sum[blo]=(sum[blo]+num[i])%mod;
	}
	for(int i=1;i<=m;++i)
	{
		int op=read();
		if(op==1)
		{
			int x=read(),y=read(),z=read();
			modify(x,y,z);
		}
		else
		{
			int l=read(),r=read();
			write(query(l,r)),puts("");
		}
	}
	return 0;
}
