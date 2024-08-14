#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
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
inline void write(int x)
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
const int N=1e6+5;
int tot,p[N];
bool isPrime[N],vis[N];
void init()
{
    for(int i=2;i<N;++i)
	{
        if(!isPrime[i])
		p[++tot]=i;
        for(int j=1;j<=tot&&i*p[j]<N;++j)
		{
            isPrime[i*p[j]]=1;
            if(!(i%p[j]))break;
        }
    }
}
int main()
{
    init();
    ll l,r;
    while(~scanf("%lld%lld",&l,&r))
	{
        memset(vis,1,sizeof(vis));
        if(l==1)vis[0]=0;
        for(int i=1;i<=tot;++i)
		{
            for(ll j=l/p[i];j*p[i]<=r;++j)
			{
                ll x=p[i]*j;
                if(j>1&&x>=l)vis[x-l]=0;
            }
        }
        ll pos=0,pos1,pos2,pos3,pos4,minn=0x3f3f3f3f3f3f3f3f,maxn=0;
        for(ll i=l;i<=r;++i)
		{
            if(!vis[i-l])continue;
            if(pos) 
			{
				if(minn>i-pos)minn=i-pos,pos1=pos,pos2=i;
				if(maxn<i-pos)maxn=i-pos,pos4=i,pos3=pos;
			}
            pos=i;
        }
        if(!maxn)puts("There are no adjacent primes.");
        else printf("%lld,%lld are closest, %lld,%lld are most distant.\n",pos1,pos2,pos3,pos4);
    }
    return 0;
}
