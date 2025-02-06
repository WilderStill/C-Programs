#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch&15);
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
	putchar(x%10+'0');
	return;
}
const int M=100010,N=1010,mod=1000000007;
int blen,tot,L[N],R[N],blo[M],num[M],sum[N],sum_sq[N];
inline int qpow(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1)res=(res*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return res%mod;
}
inline void modify(int x,int k)
{
    int p=blo[x];
    sum[p]=(sum[p]+k-num[x]+mod)%mod;
    sum_sq[p]=(sum_sq[p]+2*num[x]*(k-num[x])%mod+(k-num[x])*(k-num[x])%mod)%mod;
    num[x]=k;
    return;
}
inline int query_var(int pl,int pr)
{
	int l=blo[pl],r=blo[pr],ave=0,res=0;
	int t=(qpow(pr-pl+1,mod-2)+mod)%mod;
    if(l==r)
    {
        for(int i=pl;i<=pr;++i)
		{
			ave=(ave+num[i])%mod;
			res=(res+num[i]*num[i]%mod)%mod;
		}
        return (res*t%mod-(ave*t%mod)*(ave*t%mod)%mod+mod)%mod;
    }
    else
    {
        for(int i=pl;i<=R[l];++i)
        {
			ave=(ave+num[i])%mod;
			res=(res+num[i]*num[i]%mod)%mod;
		}
        for(int i=l+1;i<r;++i)
		{
			ave=(ave+sum[i])%mod;
			res=(res+sum_sq[i])%mod;
		}
		for(int i=L[r];i<=pr;++i)
		{
			ave=(ave+num[i])%mod;
			res=(res+num[i]*num[i]%mod)%mod;
		}
        return (res*t%mod-(ave*t%mod)*(ave*t%mod)%mod+mod)%mod;
    }
}
signed main()
{
    int n=read(),m=read();
	blen=sqrt(n);
	tot=(n-1)/blen+1;
    for(int i=1;i<=n;++i)num[i]=read();
    for(int i=1;i<=tot;++i) 
    {
        L[i]=(i-1)*blen+1,R[i]=i==tot?n:i*blen;
        for(int j=L[i];j<=R[i];++j)
		{
			blo[j]=i;
			sum[i]=(sum[i]+num[j])%mod;
			sum_sq[i]=(sum_sq[i]+num[j]*num[j]%mod)%mod;
		}
    }
    for(int i=1;i<=m;++i) 
    {
        int op=read();
        if(op==1)
        {
        	int x=read(),k=read();
            modify(x,k);
        }
        if(op==2)
		{
			int l=read(),r=read();
			int res=query_var(l,r);
			while(res<0)res+=mod;
			write(res),puts("");
		}
    }
}
