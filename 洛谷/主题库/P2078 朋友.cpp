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
int fa[100010],cnt,pos;
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
	int n=read(),m=read(),p=read(),q=read(),ans1=0,ans2=0;
	for(int i=1;i<=n+m;++i)fa[i]=i;
	for(int i=1;i<=p;++i)
	{
		int x=read(),y=read();
		if(x<y)swap(x,y);
		int xfa=find(x),yfa=find(y);
		if(xfa!=yfa)fa[xfa]=yfa;
	}
	for(int i=1;i<=q;++i)
	{
		int x=n-read(),y=n-read();
		if(x<y)swap(x,y);
		int xfa=find(x),yfa=find(y);
		if(xfa!=yfa)fa[xfa]=yfa;
	}
	for(int i=1;i<=n;++i)
		if(find(fa[i])==find(fa[1]))++ans1;
	for(int i=1;i<=m;++i)
		if(find(fa[n+i])==find(fa[n+1]))++ans2;
	write(min(ans1,ans2));
    return 0;
}

