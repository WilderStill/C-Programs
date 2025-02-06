#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read()
{
	ll x=0,f=1;
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
inline void write(ll x)
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
inline ll query(ll n)
{
    ll res=0,l=1,r;
    while(l<=n)
	{
        r=n/(n/l);
        res+=(n/l)*(r-l+1)*(l+r)/2;
        l=r+1;
    }
    return res;
}
int main()
{
    ll l=read(),r=read();
    write(query(r)-query(l-1));
    return 0;
}
