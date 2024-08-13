#include<bits/stdc++.h>
#define M 100010
#define ld long double
using namespace std;
struct point
{
    ld lx,ly;
}p[M];
bool cmp(point a,point b)
{
	return a.lx<b.lx;
}
ld dis(point a,point b)
{
    return sqrt((a.lx-b.lx)*(a.lx-b.lx)+(a.ly-b.ly)*(a.ly-b.ly));
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
    	if(n==-1)break;
    	for(int i=1;i<=n;++i)
		{
	        ld x,y;
	        scanf("%Lf %Lf",&x,&y);
	        p[i]={x,y};
	    }
	    sort(p+1,p+n+1,cmp);
	    ld ans=2e30+0.01;
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				for(int k=j+1;k<=min(j+5,n);++k)
		        ans=min(ans,dis(p[i],p[j])+dis(p[j],p[k])+dis(p[i],p[k]));
	    printf("%.3Lf\n",ans);
	}
    return 0;
}
