#include<bits/stdc++.h>
#define int long long
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
inline void file()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
}
int v[1000010];
priority_queue<int>q[2];
signed main()
{
	//file();
	int n=read(),x=read(),y=read(),z=read(),ans=0;
	for(int i=1;i<=n;++i)
	{
		int a=read(),b=read();
		for(auto id:{0,1})
		{
			for(int j=1;j<=(id?b-a:a-b);++j)
			{
				v[i]=id?x:y;
				if(!q[id].empty())
				{
					v[i]=min(v[i],i*z-q[id].top());
					q[id].pop();
				}
				q[id^1].push(v[i]+i*z);
				ans+=v[i];
			}
		}
	}
	write(ans);
    return cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n',0;
}
