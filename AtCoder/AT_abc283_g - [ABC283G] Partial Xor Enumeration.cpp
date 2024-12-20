#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int Dg=63;
inline ll readl()
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
ll num[110];
vector<ll>dk;
inline void insert(ll x)
{
	for(ll i=Dg;~i;--i)
		if(x&(1ll<<i))
		{
			if(!num[i]){num[i]=x;return;}
            x^=num[i];
		}
    return;   
}
inline void init()
{
	for(ll i=0;i<=Dg;++i)
        if(num[i])
        {
            for(int j=0;j<i;++j)if((num[i]>>j)&1)num[i]^=num[j];
            dk.push_back(num[i]);
        }
}
inline ll query(ll x)
{
    ll res=0;
    for(ll i=0;i<dk.size();++i)
        if(((x-1)>>i)&1)
            res^=dk[i];
    return res;
}
int main()
{
    ll n=readl(),l=readl(),r=readl();
    for(ll i=1;i<=n;++i)insert(readl());
    init();
    for(ll i=l;i<=r;++i)write(query(i)),putchar(' ');
    return 0;
}
