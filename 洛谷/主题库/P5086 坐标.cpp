#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
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
struct point
{
	int x[4];
	point(){x[0]=x[1]=x[2]=x[3]=0;}
	point(int a,int b,int c,int d){x[0]=a,x[1]=b,x[2]=c,x[3]=d;}
	bool operator < (point b)
	{
		for(int i=0;i<4;++i)if(x[i]^b.x[i])return x[i]<b.x[i];
	}
}p[500010];
int n,i,mi,ma;
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)
	{
		int a=read(),b=read(),c=read(),d=read();
		p[i]={b-a,c-b,d-c,i};
	}
	sort(p+1,p+n+1);
	int minn=INF,maxn=-INF;
	for(int i=2;i<=n;++i)
	{
		int cnt=0;
		for(int j=0;j<3;++j)if(p[i].x[j]==p[i-1].x[j])++cnt;
		if(cnt==3)
		{
			minn=min(minn,p[i].x[3]-p[i-1].x[3]);
			maxn=max(maxn,p[i].x[3]+p[i-1].x[3]);
		}
	}
	write(minn),putchar(' '),write(maxn);
	return 0;
}
