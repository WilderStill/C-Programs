#include<bits/stdc++.h>
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
int n,t,maxn,minn,cnt[100];
bool ifprint=0; 
inline void dfs(int res,int sum,int tg,int p)
{
    if(!res)
	{
        write(tg),puts(""),ifprint=1;
        return;
    }
    if(ifprint)return;
    if(sum==tg)
	{
        dfs(res-1,0,tg,maxn);
        return;
    }
    for(int i=p;i>=minn;--i)
	{
        if(cnt[i]&&i+sum<=tg)
		{
            cnt[i]--;
            dfs(res,sum+i,tg,i);
            cnt[i]++;
            if(!sum||sum+i==tg) break;
        }
    }
    return;
}
int main()
{
	while(~scanf("%d",&n)&&n)
	{
		minn=101,ifprint=t=0,maxn=-1;
		memset(cnt,0,sizeof cnt);
	    for(int i=1,val;i<=n;++i)
	        ++cnt[val=read()],t+=val,maxn=max(maxn,val),minn=min(minn,val);
	    for(int i=maxn;i<=(t/2);++i)
	        if(t%i==0)
				dfs(t/i,0,i,maxn);
	    if(!ifprint)write(t),puts("");
	}
    return 0;
}

