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
	int l,r,len;
}tp[100010];
priority_queue<int>ql,qr;
int n,m,L,R,ans;
signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		int l=read(),r=read(),len=r-l;
		tp[i]={l,r,len};
	}
	ql.push(tp[1].l),qr.push(-tp[1].l);
	int lt=0,rt=0;
	for(int i=2;i<=n;++i)
	{
		lt-=tp[i].len,rt+=tp[i-1].len;
		int L=lt+ql.top(),R=rt-qr.top();
		if(tp[i].l<L)
		{
			ans+=L-tp[i].l;
			ql.pop();
			ql.push(tp[i].l-lt);
			ql.push(tp[i].l-lt);
			qr.push(rt-L);
		}
		else if(tp[i].l>R)
		{
			ans+=tp[i].l-R;
			qr.pop();
			qr.push(rt-tp[i].l);
			qr.push(rt-tp[i].l);
			ql.push(R-lt);
		}
		else
		{
			ql.push(tp[i].l-lt);
			qr.push(rt-tp[i].l);
		}
	}
	write(ans);
    return cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n',0;
}
