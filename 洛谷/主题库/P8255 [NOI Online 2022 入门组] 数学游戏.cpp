#include<bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
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
inline void file()
{
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
}
int main()
{
	//file();
	int T=read();
	while(T--)
	{
		ll x=read(),z=read();
		if(z%x){puts("-1");continue;}
		z/=x;
		ll syh=__gcd(z,x*x);
		ll tp=sqrt(syh);
		if(tp*tp!=syh)puts("-1");
		else write(z/tp),puts("");
	}
    return cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n',0;
}
