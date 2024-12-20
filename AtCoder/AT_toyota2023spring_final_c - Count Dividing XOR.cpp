#include<bits/stdc++.h>
#define ll long long
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
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
int main()
{
	ll l=read(),r=read(),ans=0;
    for(ll del=1;del<=r-l;++del)
        for(ll a=((l-1)/del+1)*del;a+del<=r;a+=del)
            ans+=(a^(a+del))==del;
    write(ans);
	return 0;
}

