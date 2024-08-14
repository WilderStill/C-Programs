#include<bits/stdc++.h>
#define M 50010
#define ld long double
#define arc 1.14 
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
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
struct point
{
    int lx,ly,x,y;
}p[M];
bool cmp(point a,point b)
{
	return (a.x*a.x+a.y*a.y)<(b.x*b.x+b.y*b.y);
}
int dis(point a,point b)
{
    return (a.lx-b.lx)*(a.lx-b.lx)+(a.ly-b.ly)*(a.ly-b.ly);
}
int main()
{
    int n=read();
    for(int i=1;i<=n;++i)
	{
        int x=read(),y=read();
        p[i]={x,y,x*cos(arc)-y*sin(arc),x*sin(arc)+y*cos(arc)};
    }
    sort(p+1,p+n+1,cmp);
    int ans=0;
    for(int i=1;i<=n;++i)
	    for(int j=n;j>=max(1,n-5);--j)
	        ans=max(ans,dis(p[i],p[j]));
    write(ans);
    return 0;
}

