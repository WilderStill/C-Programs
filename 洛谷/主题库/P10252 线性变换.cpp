#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read()
{
	register ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void print(ll x)
{
	if(x<0)putchar('-'),x=-x; 
	if(x>=10) print(x/10);
	putchar(x%10+'0');
}
ll t,n,a,b;
int main()
{
	t=read();
	while(t--)
	{
		n=read(),a=read(),b=read();
		if(b==0)
		{
			if(a<0)print(n*a);
			else if(a==0)putchar('0');
			else if(a>0)print(n);
		}
		else if(b>0)
		{
			if(a<0)print(a*n-b);
			else if(a==0)print(-b);
			else if(a>0)
			{
				if(a*n<b)print(a*n-b);
				else if(a*n==b)print(-b);
				else
				{
					if(a*n>=b+n)print(n);
					else if(a==1)print(n%b-b);
					else
					{
						while(n>=0)n=a*n-b;
						print(n);
					}
				}
			}
		}
		else if(b<0)
		{
			if(a>0)print(n);
			else if(a==0)print(min(b,n));
			else if(a<0)
			{
				if(a*n-b<0)print(a*n-b);
				else if(a*n==b)print(b);
				else 
				{
					if(-a*n>=-b+n)print(n);
					else if(a==1)print(n%b-b);
					else
					{
						while(n>=0)n=a*n-b;
						print(n);
					}
				}
			}
		}
		puts("");
	}
	return 0;
}
