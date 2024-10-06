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
        x=(x<<1)+(x<<3)+(ch&15);
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
const double eps=1e-8;
struct piggy
{
	double x,y;
}p[20],tp[20];
struct throwline
{
	double a,b;
	double operator ()(const double x)
	{
		return a*x*x+b*x;
	}
}l[20];
int n,m,ans;
inline void dfs(int pos,int line,int pig)
{
	if(line+pig>=ans)return;
	if(pos==n+1)
	{
		ans=line+pig;
		return;
	}
	for(int i=1;i<=line;++i)
	{
		if(fabs(l[i](p[pos].x)-p[pos].y)<eps)
		{
			dfs(pos+1,line,pig);
			return;
		}
	}
	for(int i=1;i<=pig;++i)
	{
		if(fabs(p[pos].x-tp[i].x)<eps)continue;
		double a=(p[pos].y*tp[i].x-tp[i].y*p[pos].x)/(p[pos].x*p[pos].x*tp[i].x-tp[i].x*tp[i].x*p[pos].x);
		double b=(p[pos].y-p[pos].x*p[pos].x*a)/p[pos].x;
		if(a<0)
		{	
			l[line+1]={a,b};
			piggy tpp=tp[i];
			for(int j=i;j<pig;++j)tp[j]=tp[j+1];
			dfs(pos+1,line+1,pig-1);
			for(int j=pig;j>i;--j)tp[j]=tp[j-1];
			tp[i]=tpp;
		}
	}
	tp[pig+1]=p[pos];	
	dfs(pos+1,line,pig+1);
}
int main()
{
	//freopen("angrybirds.in","r",stdin);
	//freopen("angrybirds.out","w",stdout);
	int T=read();
	while(T--)
	{
		n=read(),m=read();
		for(int i=1;i<=n;++i)scanf("%lf%lf",&p[i].x,&p[i].y);
		ans=100;
		dfs(1,0,0);
		write(ans),puts("");
	}
    return 0;
}

