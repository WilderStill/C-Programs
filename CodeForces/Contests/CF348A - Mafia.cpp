#include<bits/stdc++.h>
#define ll long long 
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
int main()
{
	ll n=read(),sum=0,maxn=0;
	for(int i=1;i<=n;++i)
	{
		ll x=read();
		sum+=x;
		maxn=max(x,maxn);
	}
	if(!(sum%(n-1)))sum/=(n-1);
	else sum=sum/(n-1)+1;
	write(max(sum,maxn));
    return 0;
}

