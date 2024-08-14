#include<bits/stdc++.h>
#define double long double
#define M 504114
using namespace std;
struct point{
	double a[4];
	bool operator <(const point &t) const{
		return a[0]*a[1]<t.a[0]*t.a[1];
	}
}p[M];
double z,w,ans,x,y,x_,y_;
int n;
int main(){
	scanf("%d",&n);
	int k=min(n,100);
	z=sin(1),w=cos(1);
	for(int i=1;i<=n;i++){
		scanf("%Lf%Lf",&x,&y);
		p[i]=point({x*w-y*z,x*z+y*w,x,y});
	}
	stable_sort(p+1,p+n+1);
	ans=2e30+0.01;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k&&i+j<=n;j++)
		{
			x=p[i].a[2];
			y=p[i].a[3];
			x_=p[i+j].a[2],y_=p[i+j].a[3];
			z=(x-x_)*(x-x_)+(y-y_)*(y-y_);
			ans=min(ans,z);
		}
	printf("%.0Lf",ans);
	return 0;
}
