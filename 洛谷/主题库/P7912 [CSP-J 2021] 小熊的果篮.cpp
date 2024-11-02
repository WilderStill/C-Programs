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
inline void file()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}
const int INF=0x3f3f3f3f;
set<int>s[2];
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)s[read()^1].insert(i);
	s[0].insert(INF),s[1].insert(INF);
	int pos=0;
	bool fg=*s[0].begin()>=*s[1].begin();
	while(!fg&&s[0].size()>1||fg&&s[1].size()>1)
	{
		pos=*s[fg].upper_bound(pos);
		if(pos==INF)
		{
			pos=0;
			fg=*s[0].begin()>=*s[1].begin();
			puts("");
			continue;
		}
		write(pos),putchar(' ');
		s[fg].erase(pos);
		fg^=1;
	}
	puts("");
	for(auto dg:{0,1})while(s[dg].size()>1)write(*s[dg].begin()),puts(""),s[dg].erase(*s[dg].begin());
	return 0;
}

