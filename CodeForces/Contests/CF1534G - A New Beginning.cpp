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
inline void file()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}
struct node
{
	int sum,x,y;
	bool operator<(node b){return sum==b.sum?x<b.x:sum<b.sum;}
}tp[800010];
priority_queue<int>ql,qr;
signed main()
{
	int n=read();
	long long ans=0;
	for(int i=1;i<=n;++i)
	{
		int x=read(),y=read();
		tp[i]={x+y,x,y};
	}
	sort(tp+1,tp+n+1);
	ql.push(tp[1].x),qr.push(-tp[1].x);
	int rt=0;
	for(int i=2;i<=n;++i)
	{
		int delt=tp[i].sum-tp[i-1].sum;
		rt+=delt;
		int L=ql.top(),R=rt-qr.top();
		if(tp[i].x<L)
        {
            ans+=L-tp[i].x;
			ql.pop();
            ql.push(tp[i].x);
			ql.push(tp[i].x);
			qr.push(rt-L);
        }
		else if(tp[i].x>R)
		{
			ans+=tp[i].x-R;
			qr.pop();
			qr.push(rt-tp[i].x);
			qr.push(rt-tp[i].x);
			ql.push(R);
		}
		else
		{
			ql.push(tp[i].x);
			qr.push(rt-tp[i].x);
		}
	}
	write(ans);
    return cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n',0;
}
