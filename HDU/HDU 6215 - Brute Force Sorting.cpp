#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
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
struct link
{
	int l,r,val;
}num[100010];
queue<int>q;
int main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		num[0].r=1,num[n+1].val=INF;
		for(int i=1;i<=n;++i)num[i]={i-1,i+1,read()},q.push(i);
		while(!q.empty())
        {
            int top=q.front(),pre=num[top].l,nxt=num[top].r;
			q.pop();
			if(num[top].val>num[nxt].val)
            {
                q.push(pre);
                num[pre].r=num[nxt].r;
                num[num[nxt].r].l=pre;
                num[nxt].l=pre;
            }
        }
        int cnt=0,pos=num[0].r;
        while(pos<=n)
        {
        	++cnt;
        	pos=num[pos].r;
		}
        write(cnt);
        puts("");
        pos=num[0].r;
        while(pos<=n)
        {
        	write(num[pos].val);putchar(' ');
            pos=num[pos].r;
        }
        puts("");
	}
    return 0;
}

