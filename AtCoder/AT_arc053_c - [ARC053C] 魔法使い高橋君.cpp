#include<bits/stdc++.h>
#define ll long long
#define M 1000510
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
struct op
{
	ll x,y,id;
	bool operator<(const op&b)
	{
		if(id^b.id)return id<b.id;
		switch(id)
		{
			case -1:return x<b.x;
			case 0:return x<b.x;
			case 1:return y>b.y;
		}
		return 1145141919810;
	}
}change[M];
int main()
{
	ll n=read();
	for(int i=1;i<=n;++i)
	{
		change[i].x=read(),change[i].y=read();
		if(change[i].x<change[i].y)change[i].id=-1;
		if(change[i].x==change[i].y)change[i].id=0;
		if(change[i].x>change[i].y)change[i].id=1;
	}
	sort(change+1,change+n+1);
	ll ans=-0x3f3f3f3f,res=0;
	for(int i=1;i<=n;++i)
	{
		res+=change[i].x;
		ans=max(ans,res);
		res-=change[i].y;
		ans=max(ans,res);
	}
	write(ans);
	return 0;
}

