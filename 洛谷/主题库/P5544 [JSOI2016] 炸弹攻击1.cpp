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
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
struct building
{
	int x,y,r;
}b[100010];
struct human
{
	int p,q;
}h[100010];
int ans,tans,n,m,r;
double sumx=0,sumy=0;
inline double dist(double px1,double py1,double px2,double py2)
{
	return sqrt((px1-px2)*(px1-px2)+(py1-py2)*(py1-py2));
}
inline int calc(double x,double y)
{
	double res,minr=1.0*r;
	int cnt=0;
	for(int i=1;i<=n;++i)
	{
		res=dist(x,y,b[i].x,b[i].y);
		res-=1.0*b[i].r;
		minr=min(minr,res);
	}
	for(int i=1;i<=m;++i)
	{
		res=dist(x,y,h[i].p,h[i].q);
		if(res<=minr)++cnt;
	}
	return cnt;
}
inline void SA()
{
	double t=1000;
	while(t>1e-16)
	{
		double tx=(rand()*2-RAND_MAX)*t,ty=(rand()*2-RAND_MAX)*t;
		int dt=ans-calc(sumx+tx,sumy+ty);
		if(dt<0)ans=calc(sumx+tx,sumy+ty),tans=max(tans,ans),sumx+=tx,sumy+=ty;
		else if(exp(dt+t)/t<(double)rand()/RAND_MAX)ans=calc(sumx+tx,sumy+ty),sumx+=tx,sumy+=ty;
		t*=0.99;
	}
}
const int dg=50;
int main()
{
	srand(time(0));
	n=read(),m=read(),r=read();
	for(int i=1;i<=n;++i)b[i].x=read(),b[i].y=read(),b[i].r=read();
	for(int i=1;i<=m;++i)sumx+=(h[i].p=read()),sumy+=(h[i].q=read());
	sumx/=m,sumy/=m;
	for(int i=1;i<=dg;++i)SA();
	write(tans);
	return 0;
}
