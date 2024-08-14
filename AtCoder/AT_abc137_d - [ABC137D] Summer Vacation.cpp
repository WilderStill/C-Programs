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
struct syh
{
	int a,b;
}dg[100010];
bool cmp(syh x,syh y)
{
	return x.a<y.a;
}
priority_queue<int>q;
int main()
{
	int n=read(),m=read(),ans=0,idx=1;
	for(int i=1;i<=n;++i)dg[i].a=read(),dg[i].b=read();
	sort(dg+1,dg+n+1,cmp);
	for(int i=1;i<=m;++i)
	{
		for(;dg[idx].a<=i&&idx<=n;++idx)q.push(dg[idx].b);
		if(!q.empty())	
		{
			ans+=q.top();
			q.pop();
		}
	}
	write(ans);
	return 0;
}
