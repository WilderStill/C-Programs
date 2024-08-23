#include<bits/stdc++.h>
#define INF 1e18
#define M 1010
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
inline double dist(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
struct point
{
	double x,y;
	int id;
}p[M<<1],tp[M<<1];
double f[M][M][2];
int n,pos=1,pre[M][M][2];
inline void print(int l,int r,int op)
{
	if(l==r)
	{
		write(p[l].id),putchar(' ');
		return;
	}
	if(op)write(p[r].id),putchar(' '),print(l,r-1,pre[l][r][op]);
    else write(p[l].id),putchar(' '),print(l+1,r,pre[l][r][op]);
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		scanf("%lf%lf",&p[i].x,&p[i].y);
		p[i].id=i;tp[i]=p[i];
	}
	for(int i=1;i<=n;++i)if(p[i].y>p[pos].y)pos=i;
	for(int i=1;i<=pos;++i)p[i+n-pos]=tp[i];
    for(int i=pos+1;i<=n;++i)p[i-pos]=tp[i];
	for(int len=2;len<n;++len)
		for(int i=1,j=i+len-1;i<=n;++i,++j)
		{
			double dis;
			f[i][j][0]=f[i][j][1]=INF;
			if((dis=f[i+1][j][0]+dist(p[i].x,p[i].y,p[i+1].x,p[i+1].y))<f[i][j][0])f[i][j][0]=dis,pre[i][j][0]=0;
            if((dis=f[i+1][j][1]+dist(p[i].x,p[i].y,p[j].x,p[j].y))<f[i][j][0])f[i][j][0]=dis,pre[i][j][0]=1;
            if((dis=f[i][j-1][0]+dist(p[i].x,p[i].y,p[j].x,p[j].y))<f[i][j][1])f[i][j][1]=dis,pre[i][j][1]=0;
            if((dis=f[i][j-1][1]+dist(p[j-1].x,p[j-1].y,p[j].x,p[j].y))<f[i][j][1])f[i][j][1]=dis,pre[i][j][1]=1;
		}
	write(p[n].id),putchar(' ');
	print(1,n-1,f[1][n-1][0]+dist(p[1].x,p[1].y,p[n].x,p[n].y)>f[1][n-1][1]+dist(p[n-1].x,p[n-1].y,p[n].x,p[n].y));
    return 0;
}
