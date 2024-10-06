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
struct zf
{
	int x1,y1,x2,y2;
	friend bool operator!(zf b){return (!b.x1)&&(!b.y1)&&(!b.x2)&&(!b.y2);}
}p[500010],ans[5];
mt19937 dg(time(NULL));
int main()
{
	int n=read(),k=read();
	for(int i=1;i<=n;++i)p[i].x1=read(),p[i].y1=read(),p[i].x2=read(),p[i].y2=read();
	while(true)
	{
		auto U=[](zf a,zf b)
		{
			int lx=max(a.x1,b.x1),rx=min(a.x2,b.x2),dy=max(a.y1,b.y1),uy=min(a.y2,b.y2);
			if(lx>rx||dy>uy)return (zf){0,0,0,0};
			else return (zf){lx,dy,rx,uy};
		};
		bool fg=1;
		for(int i=1;i<=k;++i)ans[i]=p[i];
		for(int i=1;i<=n;++i)
		{
			int tp=0;
			for(int j=1;j<=k;++j)if(!(!U(p[i],ans[j])))tp=j;
			if(!tp)
			{
				fg=0;
				swap(p[i],p[dg()%k+1]);
				break;
			}
			ans[tp]=U(p[i],ans[tp]);
		}
		if(fg)
		{
			for(int i=1;i<=k;++i)write(ans[i].x1),putchar(' '),write(ans[i].y2),puts("");
			return 0;
		}
	}
    return 0;
}
