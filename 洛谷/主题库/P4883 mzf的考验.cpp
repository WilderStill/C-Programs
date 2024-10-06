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
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
vector<ll>v;
int cl=7; 
int main()
{
	int n=read(),m=read();
	v.emplace_back(0);
	for(int i=1;i<=n;++i)v.emplace_back(read());
	for(int i=1;i<=m;++i)
	{
		int op=read();
		if(op==1)
		{
			int l=read(),r=read();
			reverse(v.begin()+l,v.begin()+r+1);
		}
		if(op==2)
		{
			int l=read(),r=read();ll d=read();
			for(;l<=r-cl;l+=cl)v[l]^=d,v[l+1]^=d,v[l+2]^=d,v[l+3]^=d,v[l+4]^=d,v[l+5]^=d,v[l+6]^=d;
			for(;l<=r;++l)v[l]^=d;
		}
		if(op==3)
		{
			int l=read(),r=read();
			ll sum=0;
			for(;l<=r-cl;l+=cl)sum+=(v[l]+v[l+1]+v[l+2]+v[l+3]+v[l+4]+v[l+5]+v[l+6]);
			for(;l<=r;++l)sum+=v[l];
			write(sum);
			puts("");
		}
	}
    return 0;
}

