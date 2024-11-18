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
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}
struct node
{
	int t,d,x;
	bool operator<(node b){return t<b.t;}
}p[200010];
priority_queue<int>ql,qr;
signed main()
{
	//file();
	int n=read(),ans=0;
	for(int i=1;i<=n;++i)p[i]={read(),read(),read()};
	sort(p+1,p+n+1);
    int lt=0,rt=0;
    for(int i=1;i<=n;++i)ql.push(0),qr.push(0);
    for(int i=1;i<=n;++i)
    {
        int delt=p[i].t-p[i-1].t;
        lt-=delt,rt+=delt;
        if(!p[i].d)
        {
            if(p[i].x>rt-qr.top())
            {
                ans+=p[i].x+qr.top()-rt;
                ql.push(-qr.top()+rt-lt);
                qr.pop();
                qr.push(rt-p[i].x);
            }
            else ql.push(p[i].x-lt);
        }
        else
        {
            if(p[i].x<ql.top()+lt)
            {
                ans+=ql.top()+lt-p[i].x;
                qr.push(rt-lt-ql.top());
                ql.pop();
                ql.push(p[i].x-lt);
            }
            else qr.push(rt-p[i].x);
        }
    }
    write(ans);
    return cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n',0;
}
