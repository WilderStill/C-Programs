#include<bits/stdc++.h>
#define maxlim 1e6
#define ll __int128
using namespace std;
inline ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
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
set<ll>s;
int main()
{
	ll n=read(),ans=sqrtl(n);
	for(ll i=2;i<=maxlim;++i)
	{
        ll pw=i*i;
        while(pw<=n)
		{
			ll rt=sqrtl(pw);
            if(rt*rt!=pw)s.insert(pw);
            pw*=i;
        }
    }
    ans+=s.size();
	write(ans);
	return 0;
}
