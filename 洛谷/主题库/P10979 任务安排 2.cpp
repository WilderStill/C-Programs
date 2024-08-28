#include<bits/stdc++.h>
#define M 300010
#define ll long long
#define ld long double
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
ll hd,tl,f[M],q[M],sumt[M],sumc[M];
ll X(ll i1){return sumc[i1];}
ll Y(ll i1){return f[i1];}
ld k(ll i1,ll i2)
{
	if(X(i1)^X(i2))return (ld)((ld)(Y(i2)-Y(i1)))/((ld)(X(i2)-X(i1)));
	return Y(i2)>=Y(i1)?1e18:-1e18;
}
ll search(ll x)
{
	if(hd==tl)return q[hd];
    ll l=hd,r=tl;
    while(l<r)
	{
        ll mid=(l+r)>>1;
        if(k(q[mid],q[mid+1])<x)l=mid+1;
        else r=mid;
    }
    return q[l];
}
int main()
{
	int n=read(),s=read();
	for(int i=1,c,t;i<=n;++i)
	{
		t=read(),c=read();
		sumt[i]=sumt[i-1]+t;
		sumc[i]=sumc[i-1]+c;
	}
	q[++tl]=0;
    for(ll i=1;i<=n;++i)
	{
        ll j=search(s+sumt[i]);
        f[i]=f[j]+sumt[i]*(sumc[i]-sumc[j])+s*(sumc[n]-sumc[j]);
        while(hd<tl&&k(q[tl-1],q[tl])>=k(q[tl-1],i))--tl;
        q[++tl]=i;
    }
    write(f[n]);
	return 0;
}
