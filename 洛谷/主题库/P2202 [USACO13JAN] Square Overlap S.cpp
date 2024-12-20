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
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
struct point
{
	int x,y;
	bool operator<(point b){return x<b.x;}
}p[500010];
int main()
{
	int n=read(),k=read(),ans=0;
	for(int i=1;i<=n;++i)p[i]={read(),read()};
	sort(p+1,p+n+1);
	for(int i=1;i<n;++i)
		for(int j=i+1;j<=n;++j)
		{
			if(p[i].x+k<=p[j].x)break;
			if(1.0*clock()/CLOCKS_PER_SEC>=0.95)
			{
				write(ans);
				return 0;
			}
			if(abs(p[i].y-p[j].y)<k)
			{
				if(ans)
				{
					puts("-1");
					return 0;
				}
				ans=(k-(p[j].x-p[i].x))*(k-abs(p[j].y-p[i].y));
			}
		}
	write(ans);
	return 0;
}

