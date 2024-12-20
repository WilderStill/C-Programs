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
vector<ll>v;
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)
	{
		ll x=read();
		v.emplace_back(x);
	}
	for(int i=1;i<=n;++i)
	{
		ll op=read(),l=read(),r=read(),c=read();
		if(op)write(v[r-1]),puts("");
		else v.insert(v.begin()+l-1,r);
	}
	return 0;
}

