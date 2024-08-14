#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll p=1e9+7;
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
ll qpow(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		if(y&1)res=res*x%p;
		x=x*x%p;
		y>>=1;
	}
	return res%p;
}
ll n,m,l,r,k,sum;
char x;
int main()
{
	n=read();m=read();l=read();r=read();
	while(!isdigit(x))x=getchar();
	for(int i=1;i<=n;++i)
	{
		sum=((sum<<1)+(sum<<3)+(x^48))%m;
		if(!sum)k++;
		x=getchar();
	}
	if(sum)puts("0");
	else write(qpow(2,k-1)); 
	return 0;
}
