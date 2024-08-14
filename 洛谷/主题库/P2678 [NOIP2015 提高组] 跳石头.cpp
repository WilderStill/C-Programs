#include<bits/stdc++.h>
#define M 500010
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
int d,n,m,val[M];
bool check(int x)
{
	int cnt=0,pos=0;
	for(int i=1;i<=n;++i)
	{
		if(val[i]-val[pos]<x)++cnt;
		else pos=i;
	}
	return cnt<=m;
}
int main()
{
	d=read(),n=read(),m=read();
	for(int i=1;i<=n;++i)val[i]=read();
	val[++n]=d;
	int l=1,r=d;
	while(l<=r)
	{
		int mid=(l+r)>>1;
        if(check(mid))l=mid+1;
        else r=mid-1;
	}
	write(l-1);
	return 0;
}
