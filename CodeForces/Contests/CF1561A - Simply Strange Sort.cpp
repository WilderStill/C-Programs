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
ll num[200010];
int main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n;++i)num[i]=read();
		for(int i=1;;++i)
		{
			bool fg=0;
			for(int j=1;j<=n;++j)if(num[j]^j){fg=1;break;}
			if(!fg){write(i-1);puts("");break;}                         
			if(i&1)
			{
				for(int j=1;j<=n-2;j+=2)
					if(num[j]>num[j+1])
						swap(num[j],num[j+1]);	
			}
			else
			{
				for(int j=2;j<=n-1;j+=2)
					if(num[j]>num[j+1]) 
						swap(num[j],num[j+1]);
			}	
		}
	}
    return 0;
}

