#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
	return x*f;
}
typedef long double ld;
struct Point{ld x,y;}p[100010];
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)scanf("%Lf%Lf",&p[i].x,&p[i].y);
	p[0]=p[n];
	ld ans=0;
	for(int i=1;i<=n;++i)ans+=(p[i].x*p[i-1].y)-(p[i-1].x*p[i].y);
	ans=fabs(ans);
	for(int i=1;i<=n;++i)
	{
		if(p[i-1].x==p[i].x){ans-=0.5*fabs(p[i].y-p[i-1].y);continue;}
		if(p[i-1].y==p[i].y){ans-=0.5*fabs(p[i].x-p[i-1].x);continue;}
	}
	printf("%.6Lf",ans);
	return 0;
}
