#include<bits/stdc++.h>
#define M 114514
#define ll long long
using namespace std; 
ll n;
double f[M][30],ans=1e9,ax,ay;
double calc(double x0,double y0)
{
	double res=0;
	for(int i=1;i<=n;i++)
	{
		double x=f[i][1]-x0,y=f[i][2]-y0;
		res+=f[i][3]*sqrt(x*x+y*y);
	}
	return res;
}
void sa()
{
	double t=3000;
	while(t>1e-16)
	{
		double x=ax+(rand()*2-RAND_MAX)*t,y=ay+(rand()*2-RAND_MAX)*t,dt;
		dt=calc(x,y)-ans;
		if(dt<0)ans=calc(x,y),ax=x,ay=y;
		else if(exp(dt+t)/t<(double)rand()/RAND_MAX) ax=x,ay=y;
		t*=0.99;
	}
}

int main()
{
	srand(19261145);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lf%lf%lf",&f[i][1],&f[i][2],&f[i][3]);
	ans=calc(ax/1.0*n,ay/1.0*n);
	for(int i=1;i<=4;i++)sa();
	printf("%.3lf %.3lf",ax,ay);
	return 0;
}
