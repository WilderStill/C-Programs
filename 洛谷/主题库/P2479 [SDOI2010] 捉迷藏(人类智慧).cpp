#include<bits/stdc++.h>
#define int long long
#define M 100010
#define ld long double
#define arc 1.14 
using namespace std;
inline int read()
{
	int x=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	return x;
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
struct point{int x,y;}p[M];
inline bool cmp(point a,point b){return a.x<b.x;}
inline int dis(point a,point b){return abs(a.x-b.x)+abs(a.y-b.y);}
signed main()
{
    int n=read();
    for(int i=1;i<=n;++i)p[i]={read(),read()};
    sort(p+1,p+n+1,cmp);
    int a=2e9,b=2e9,c=2e9,d=2e9;
    for(int i=1;i<=n;++i)
    {
    	a=min(a,p[i].x+p[i].y);
    	b=min(b,p[i].x-p[i].y);
    	c=min(c,-p[i].x+p[i].y);
    	d=min(d,-p[i].x-p[i].y);
	}
    int ans=2e9;
    for(int i=1;i<=n;++i)
    {
    	int ans1=max({p[i].x+p[i].y-a,p[i].x-p[i].y-b,-p[i].x+p[i].y-c,-p[i].x-p[i].y-d}),ans2=2e9;
		for(int j=max(i-450,1ll);j<=min(i+450,n);++j)
	        if(i^j)ans2=min(ans2,dis(p[i],p[j]));
		ans=min(ans,ans1-ans2);
	}
    write(ans);
    return 0;
}