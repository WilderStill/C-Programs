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
vector<int>syh(500100);
bool fg=0;
signed main()
{
	int n=read(),m=read();
	for(int i=1;i<=m;++i)
	{
		int op=read();
		if(op==1)
		{
			fg=1;
			int l=read(),r=read(),v=read();
			for(int j=l;j<=r;++j)syh[j]+=v;
		}
		if(op==2)
		{
			int l=read(),r=read();
			if(!fg)continue;
			reverse(syh.begin()+l,syh.begin()+r+1);
		}
		if(op==3)
		{
			int l=read(),r=read(),maxn=-0x3f3f3f3f3f3f3f3f;
			if(!fg){puts("0");continue;}
			for(int j=l;j<=r;++j)maxn=max(syh[j],maxn);
			write(maxn),puts("");
		}
	}
    return 0;
}
