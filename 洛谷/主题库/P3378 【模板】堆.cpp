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
priority_queue<int,vector<int>,greater<int>>q;
signed main()
{
    int n=read();
    for(int i=1;i<=n;++i)
	{
        int op=read();
        if(op==1)
        {
        	int x=read();
        	q.push(x);
		}
		if(op==2)write(q.top()),putchar('\n');
		if(op==3)q.pop();
    }
    return 0;
}
