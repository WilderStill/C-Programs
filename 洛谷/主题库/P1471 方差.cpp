#include<bits/stdc++.h>
using namespace std;
typedef double db;
const int M=100010,N=1010;
int blen,tot,L[N],R[N],blo[M];
db num[M],mk[N],sum[N],sum_sq[N];
inline void modify(int pl,int pr,db k)
{
    int l=blo[pl],r=blo[pr];
    if(l==r)
    {
        for(int i=pl;i<=pr;++i)
		{
			sum[l]+=k;
			sum_sq[l]+=2.0*num[i]*k+k*k;
			num[i]+=k;
		}
        return;
    }
    for(int i=pl;i<=R[l];++i)
	{
		sum[l]+=k;
		sum_sq[l]+=2.0*num[i]*k+k*k;
		num[i]+=k;
	}
	for(int i=l+1;i<r;++i)mk[i]+=k;
    for(int i=L[r];i<=pr;++i)
	{
		sum[r]+=k;
		sum_sq[r]+=2.0*num[i]*k+k*k;
		num[i]+=k;
	}
    return;
}
inline db query_ave(int pl,int pr)
{
    int l=blo[pl],r=blo[pr];
    db res=0;
    if(l==r)
    {
        for(int i=pl;i<=pr;++i)res+=num[i]+mk[l];
        return res*1.0/(pr-pl+1);
    }
    else
    {
        for(int i=pl;i<=R[l];++i)res+=num[i]+mk[l];
        for(int i=l+1;i<r;++i)res+=sum[i]+mk[i]*blen;
		for(int i=L[r];i<=pr;++i)res+=num[i]+mk[r];
        return res*1.0/(pr-pl+1);
    }
}
inline db query_var(int pl,int pr)
{
	int l=blo[pl],r=blo[pr];
    db ave=0,res=0;
    if(l==r)
    {
        for(int i=pl;i<=pr;++i)
		{
			ave+=num[i]+mk[l];
			res+=(num[i]+mk[l])*(num[i]+mk[l]);
		}
        return res*1.0/(pr-pl+1)-(ave*1.0/(pr-pl+1))*(ave*1.0/(pr-pl+1));
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
			res+=sum_sq[i]+2.0*sum[i]*mk[i]+blen*mk[i]*mk[i];
		}
		for(int i=L[r];i<=pr;++i)
		{
			ave+=num[i]+mk[r];
			res+=(num[i]+mk[r])*(num[i]+mk[r]);
		}
        return res*1.0/(pr-pl+1)-(ave*1.0/(pr-pl+1))*(ave*1.0/(pr-pl+1));
    }
}
int main()
{
    int n=read(),m=read();
	blen=sqrt(n);
	tot=(n-1)/blen+1;
    for(int i=1;i<=n;++i)scanf("%lf",&num[i]);
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
			db k;
			scanf("%lf",&k);
            modify(l,r,k);
        }
        if(op==2)printf("%.4lf\n",query_ave(l,r));
        if(op==3)printf("%.4lf\n",query_var(l,r));
    }
}
