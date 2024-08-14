#include<bits/stdc++.h>
#define M 11451
#define ll long long
using namespace std;
ll n,m,cost,f[M];
inline ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int main()
{
    n=read(),m=read(),cost=read();
    for(register ll i=1,x,y,z;i<=n;++i)
	{
		y=read(),x=read(),z=read();
        if(z*y>cost)//完全背包 
            for(register ll j=y;j<=cost;++j)
                f[j]=max(f[j],f[j-y]+x);
        else//多重背包（二进制） 
		{
	        for(register ll k=1;k<=z;k<<=1)
			{
	            for(register ll j=cost;j>=y*k;--j)
	                f[j]=max(f[j],f[j-y*k]+x*k);
	            z-=k;
        	}
	        if(z>0)
	        	for(register ll j=cost;j>=y*z;--j)
	            	f[j]=max(f[j],f[j-y*z]+x*z);
		}
	}
    for(register ll i=1,a,b,c;i<=m;++i)//暴力枚举 
	{
		a=read(),b=read(),c=read();
        for(register ll j=cost;j>=0;--j)
            for(register ll k=0;k<=j;++k)
                f[j]=max(f[j],f[j-k]+a*k*k+b*k+c);
    }
    printf("%lld",f[cost]);
    return 0;
}
