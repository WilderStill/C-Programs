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
struct per
{
	int s,t;
}sb[100010];
struct sta
{
	int go,lst,in;
}st[100010];
int dis[100010];
int main()
{
	int n=read(),m=read(),k=read();
	for(int i=1;i<n;++i)dis[i]=read();
	for(int i=1;i<=m;++i)
	{
		int t=read(),a=read(),b=read();
		sb[i].s=t,sb[i].t=b;
		st[a].lst=max(st[a].lst,t);
    	++st[b].go;
	}
	int tmd=0;
    for(int i=1;i<=n;++i)
    {
        st[i].in=tmd;
        tmd=max(tmd,st[i].lst);
        tmd+=dis[i];
    }
    int maxn,pos;
    for(int t=1;t<=k;++t)
    {
		maxn=0;
    	for(int i=1;i<n;++i)
    	{
    		if(!dis[i])continue;
    		int sum=0;
    		for(int j=i+1;j<=n;++j)
    		{
    			sum+=st[j].go;
    			if(st[j].in<=st[j].lst)break;
    		}
    		if(sum>maxn)maxn=sum,pos=i;
    	}
    	--dis[pos];
    	for(int i=pos+1;i<=n;++i)
    	{
    		--st[i].in;
    		if(st[i].in<st[i].lst)break;
    	}
    }
    int ans=0;
    for(int i=1;i<=m;++i)ans+=st[sb[i].t].in-sb[i].s;
    write(ans);
    return cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n',0;
}

