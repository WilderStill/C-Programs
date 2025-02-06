#include<bits/stdc++.h>
#define int long long
using namespace std;
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
const int M=100010,N=1010;
int blen,tot,L[N],R[N],blo[M],num[M],mk[N],sum[N],sum_sq[N],syha,syhb;
inline void modify(int pl,int pr,int k)
{
    int l=blo[pl],r=blo[pr];
    if(l==r)
    {
        for(int i=pl;i<=pr;++i)
		{
			sum[l]+=k;
			sum_sq[l]+=2*num[i]*k+k*k;
			num[i]+=k;
		}
        return;
    }
    for(int i=pl;i<=R[l];++i)
	{
		sum[l]+=k;
		sum_sq[l]+=2*num[i]*k+k*k;
		num[i]+=k;
	}
	for(int i=l+1;i<r;++i)mk[i]+=k;
    for(int i=L[r];i<=pr;++i)
	{
		sum[r]+=k;
		sum_sq[r]+=2*num[i]*k+k*k;
		num[i]+=k;
	}
    return;
}
inline void query_ave(int pl,int pr)
{
    int l=blo[pl],r=blo[pr],res=0;
    int t=(pr-pl+1);
    if(l==r)
    {
        for(int i=pl;i<=pr;++i)res+=num[i]+mk[l];
        syha=res;
        syhb=t;
        return;
    }
    else
    {
        for(int i=pl;i<=R[l];++i)res+=num[i]+mk[l];
        for(int i=l+1;i<r;++i)res+=sum[i]+mk[i]*blen;
		for(int i=L[r];i<=pr;++i)res+=num[i]+mk[r];
		syha=res;
        syhb=t;
        return;
    }
}
inline void query_var(int pl,int pr)
{
	int l=blo[pl],r=blo[pr],ave=0,res=0;
	int t=(pr-pl+1);
    if(l==r)
    {
        for(int i=pl;i<=pr;++i)
		{
			ave+=num[i]+mk[l];
			res+=(num[i]+mk[l])*(num[i]+mk[l]);
		}
		syha=res*t-ave*ave;
        syhb=t*t;
        return;
    }
    else
    {
        for(int i=pl;i<=R[l];++i)
        {
			ave+=num[i]+mk[l];
			res+=(num[i]+mk[l])*(num[i]+mk[l]);
		}
        for(int i=l+1;i<r;++i)
		{
			ave+=sum[i]+mk[i]*blen;
			res+=sum_sq[i]+2*sum[i]*mk[i]+blen*mk[i]*mk[i];
		}
		for(int i=L[r];i<=pr;++i)
		{
			ave+=num[i]+mk[r];
			res+=(num[i]+mk[r])*(num[i]+mk[r]);
		}
		syha=res*t-ave*ave;
        syhb=t*t;
        return;
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
			sum[i]+=num[j];
			sum_sq[i]+=(num[j]*num[j]);
		}
    }
    for(int i=1;i<=m;++i) 
    {
        int op=read(),l=read(),r=read();
        if(op==1)
        {
			int k=read();
            modify(l,r,k);
        }
        if(op==2)
		{
			query_ave(l,r);
			int g=__gcd(syha,syhb);
			write(syha/g),putchar('/'),write(syhb/g),puts("");
		}
        if(op==3)
        {
        	query_var(l,r);
			int g=__gcd(syha,syhb);
			write(syha/g),putchar('/'),write(syhb/g),puts("");
		}
    }
}

