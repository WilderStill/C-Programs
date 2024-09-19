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
int n,m,a[200010],sum[200010],ans,c[200010];
inline void merge(int l,int r)
{
	if(l==r)return;
	int mid=(l+r)>>1,i=l,j=mid+1,k=l;
	merge(l,mid),merge(mid+1,r);
    while(i<=mid&&j<=r)
	{
        if(sum[i]<sum[j])
		{
            (ans+=(mid-i+1))%=92084931;
            c[k++]=sum[j++];
        }
        else if(sum[i]>=sum[j])c[k++]=sum[i++];
    }
    while(i<=mid)c[k++]=sum[i++];
    while(j<=r)c[k++]=sum[j++];
    for(int i=l;i<=r;++i)sum[i]=c[i];
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;++i)
	{
        a[i]=read()-m;
        sum[i]=sum[i-1]+a[i];
    }
    merge(0,n);
    write(ans);
    return 0;
}
