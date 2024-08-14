#include<bits/stdc++.h>
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
struct road
{
	int x,y,t;
}r[100010];
bool cmp(road a,road b)
{
	return a.t<b.t;
}
int fa[100010],cnt,pos;
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i)
		r[i].x=read(),r[i].y=read(),r[i].t=read();
	sort(r+1,r+m+1,cmp);
	for(int i=1;i<=m;++i)
	{
		int xfa=find(r[i].x),yfa=find(r[i].y);
		if(xfa!=yfa)fa[xfa]=yfa,++cnt;
		if(cnt==n-1)
		{
			pos=i;
			break;
		}
	}
	if(cnt^n-1)puts("-1");
	else write(r[pos].t);
    return 0;
}

