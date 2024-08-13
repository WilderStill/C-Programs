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
int val[100010],sum[100010],ans;
priority_queue<int,vector<int>,greater<int>>q;
signed main()
{
	int n=read();
	for(int i=1;i<=n;++i)val[i]=read(),sum[i]+=val[i];
	for(int i=1;i<=n;++i,ans=0)
	{
		int x=read();
		sum[i]=sum[i-1]+x;
		q.push(val[i]+sum[i-1]);
		while(!q.empty()&&q.top()<=sum[i])
		{
			ans+=q.top()-sum[i-1];
			q.pop();
		}
		ans+=x*q.size();
		write(ans),putchar(' ');
	}
	return 0;
}

