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
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
ll sum[50010],f[50010];
int main()
{
	int n=read(),l=read()+1;
	for(int i=1,x;i<=n;++i)x=read(),sum[i]+=sum[i-1]+x+1;
	memset(f,0x3f,sizeof f);
	f[0]=0;
	for(int i=1;i<=n;++i)
		for(int j=0;j<i;++j)
			f[i]=min(f[i],f[j]+(sum[i]-l-sum[j])*(sum[i]-l-sum[j]));
	write(f[n]);
	return 0;
}

