#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;
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
int n,num[50010];
int main()
{
	n=read();
	for(int i=1;i<=n;++i)num[i]=read();
	for(int i=1;i<=n;++i)
	{
		int op=read(),l=read(),r=read(),c=read();
		if(!op)for(int j=l;j<=r;++j)num[j]=sqrt(num[j]);
		else
		{
			ll res=0;
			for(int j=l;j<=r;++j)res+=num[j];
			write(res);
			puts("");
		}
	}
	return 0;
}

