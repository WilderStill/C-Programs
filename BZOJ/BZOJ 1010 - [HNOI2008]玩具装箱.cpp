#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
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
ll sum[50010],f[50010],q[50010],hd=1,tl=0,n,l;
ll X(ll i1)
{
	return sum[i1];
}
ll Y(ll i1)
{
	return f[i1]+(sum[i1]+l)*(sum[i1]+l);
}
ld k(ll i1,ll i2)
{
	return (ld)((ld)(Y(i2)-Y(i1)))/((ld)(X(i2)-X(i1)));
}
int main()
{
	n=read(),l=read()+1;
	for(ll i=1,x;i<=n;++i)x=read(),sum[i]+=sum[i-1]+x+1;
	q[++tl]=0;
	for(ll i=1;i<=n;++i)
	{
		while(hd<tl&&k(q[hd],q[hd+1])<=2*sum[i])++hd;
		f[i]=f[q[hd]]+(sum[i]-sum[q[hd]]-l)*(sum[i]-sum[q[hd]]-l);
		while(hd<tl&&k(q[tl-1],q[tl])>=k(q[tl-1],i))--tl;
		q[++tl]=i;
	}
	write(f[n]);
	return 0;
}
