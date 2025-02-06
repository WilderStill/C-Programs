#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
	return x;
}
inline void write(int x)
{
	if(x>9)write(x/10);
	putchar(x%10+'0');
	return;
}
int n,m,blen,tot,L[1010],R[1010],sum[1010],mk[1010],num[100010],blo[100010],rk[100010];
struct node
{
    int op,l,r;
}q[100010];
inline void update(int pos)
{
    for(int i=L[pos];i<=R[pos];++i)rk[i]=mk[pos]-1;
    mk[pos]=0;
}
inline int query(int pl,int pr)
{
    int l=blo[pl],r=blo[pr],res=0;
    if(l==r)
	{
        if(mk[l]>1)res=pr-pl+1;
        if(!mk[l])for(int i=pl;i<=pr;++i)res+=rk[i];
        return res;
    }
    if(mk[l]>1)res+=R[l]-pl+1;
    if(!mk[l])for(int i=pl;i<=R[l];++i)res+=rk[i];
    for(int i=l+1;i<r;++i)res+=sum[i];
    if(mk[r]>1)res+=pr-L[r]+1;
    if(!mk[r])for(int i=L[r];i<=pr;++i)res+=rk[i];
    return res;
}
inline void modify(int pl,int pr,bool op)
{
    int l=blo[pl],r=blo[pr],i;
    if(pl>pr)return;
    if(l==r)
	{
        if(mk[l])update(l);
        for(int i=pl;i<=pr;++i)sum[blo[i]]+=op-rk[i],rk[i]=op;
        return;
    }
    if(mk[l])update(l);
    for(int i=pl;i<=R[l];++i)sum[blo[i]]+=op-rk[i],rk[i]=op;
    for(int i=l+1;i<r;++i)
	{
        sum[i]=op?blen:0;
        mk[i]=op+1;
    }
    if(mk[r])update(r);
    for(int i=L[r];i<=pr;++i)sum[blo[i]]+=op-rk[i],rk[i]=op;
    return;
}
inline bool check(int x,int pos)
{
    memset(sum,0,sizeof sum);
    memset(rk,0,sizeof rk);
    memset(mk,0,sizeof mk);
    for(int i=1;i<=n;++i)if(num[i]>x)++sum[blo[i]],rk[i]=1;
    for(int i=1;i<=m;++i)
	{
        int l=q[i].l,r=q[i].r,sum=query(l,r);
        if(q[i].op)
		{
            modify(l,l+sum-1,1);
            modify(l+sum,r,0);
        }
        else
		{
            modify(r-sum+1,r,1);
            modify(l,r-sum,0);
        }
    }
    return mk[blo[pos]]==2||(rk[pos]==1&&!mk[blo[pos]]);
}
int main()
{
    n=read(),m=read();
    blen=sqrt(n);
    tot=(n-1)/blen+1;
    for(int i=1;i<=n;++i)num[i]=read(),blo[i]=(i-1)/blen+1;
    for(int i=1;i<=tot;++i)L[i]=(i-1)*blen+1,R[i]=i==tot?n:i*blen;
    for(int i=1;i<=m;++i)q[i]={read(),read(),read()};
    int l=1,r=n,pos=read();
    while(l<=r)
	{
        int mid=(l+r)>>1;
        if(check(mid,pos))l=mid+1;
        else r=mid-1;
    }
    write(l);
    return 0;
}
