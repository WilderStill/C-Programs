#include<bits/stdc++.h>
#define M 50010
#define ld long double
#define arc 1.14 
using namespace std;
struct point
{
    ld lx,ly,x,y;
}p[M];
bool cmp(point a,point b)
{
	return a.x<b.x;
}
ld dis(point a,point b)
{
    return (a.lx-b.lx)*(a.lx-b.lx)+(a.ly-b.ly)*(a.ly-b.ly);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
	{
        ld x,y;
        scanf("%Lf %Lf",&x,&y);
        p[i]={x,y,x*cos(arc)-y*sin(arc),x*sin(arc)+y*cos(arc)};
    }
    sort(p+1,p+n+1,cmp);
    ld ans1=-0.1,ans2=2e30+0.01;
    for(int i=1;i<=n;++i)
	    for(int j=n;j>=n-10&&j>=i;--j)
	        ans1=max(ans1,dis(p[i],p[j]));
	for(int i=1;i<=n;++i)
	    for(int j=i+1;j<=n&&j<=i+5;++j)
	        ans2=min(ans2,dis(p[i],p[j]));
    printf("%.5Lf %.5Lf",sqrt(ans2),sqrt(ans1));
    return 0;
}
