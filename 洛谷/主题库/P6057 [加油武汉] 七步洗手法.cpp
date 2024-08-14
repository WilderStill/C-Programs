#include<bits/stdc++.h>
#define M 1001000
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
inline void write(long long x)
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
int ind[M];
long long ans;
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		++ind[u];++ind[v];
	}
	for(int i=1;i<=n;++i)
        ans+=(1ll*ind[i]*(n-1-ind[i]));
    write(1ll*n*(n-1)*(n-2)/6-(ans>>1));
	return 0;
}

