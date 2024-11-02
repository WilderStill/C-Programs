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
struct day{int l,r,id;};
deque<day>q;
int main()
{
	int n=read(),ans=1;
	for(int i=1;i<=n;++i)
	{
		int l=read(),r=read();
		while(!q.empty()&&q.front().l>r)q.pop_front();
		if(!q.empty())ans=max(ans,i-q.front().id+1);
		int tpos=i;
		while(!q.empty()&&q.back().l<l)
		{
			tpos=q.back().id;
			q.pop_back();
		}
		q.push_back({l,r,tpos});
	}
	write(ans);
	return cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n',0;
}
