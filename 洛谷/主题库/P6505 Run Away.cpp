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
struct point
{
	int x,y;
}p[100010];
int x,y,m;
double ans,ansx,ansy;
inline double newrd(double l,double r){return rand()*(r-l)/RAND_MAX+l;}
inline double dist(double px1,double py1,double px2,double py2)
{
	return sqrt((px1-px2)*(px1-px2)+(py1-py2)*(py1-py2));
}
inline double calc(double px,double py)
{
	double res=0x3f3f3f3f3f;
	for(int i=1;i<=m;++i)res=min(res,dist(px,py,p[i].x,p[i].y));
	return res;
}
inline void SA()
{
	double ax=ansx,ay=ansy,t=100000;
	while(t>1e-16)
	{
		double tx=newrd(max(ax-t,0.0),min(ax+t,x*1.0)),ty=newrd(max(ay-t,0.0),min(ay+t,y*1.0));
		double dt=ans-calc(tx,ty);
		if(dt<0)ans=calc(tx,ty),ansx=ax=tx,ansy=ay=ty;
		else if(exp(dt+t)/t<(double)rand()/RAND_MAX)ax=tx,ay=ty;
		t*=0.99;
	}
}
const int dg=30;
int main()
{
	srand(time(0));
	x=read(),y=read(),m=read();
	for(int i=1;i<=m;++i)p[i].x=read(),p[i].y=read();
	ansx=newrd(0,x),ansy=newrd(0,y);
	ans=calc(ansx,ansy);
	for(int i=1;i<=dg;++i)SA();
	printf("%lf\n",ans);
	return 0;
}

