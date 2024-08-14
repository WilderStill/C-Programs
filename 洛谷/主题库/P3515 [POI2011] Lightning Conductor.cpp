#include<bits/stdc++.h>
#define M 500100
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
int n,a[M];
double f[M];
double value(int posi,int posj)
{
	return 1.0*a[posi]+sqrt(posj-posi);
}
void solve(int l,int r,int posl,int posr)
{
	if(l>r)return;
	int mid=(l+r)>>1,pos=0;
	double res=0;
	for(int i=posl;i<=min(posr,mid);++i)
	{
		double val=value(i,mid);
		if(val>res)res=val,pos=i;
	}
	f[mid]=max(res,f[mid]);
	solve(l,mid-1,posl,pos);
	solve(mid+1,r,pos,posr);
}
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	solve(1,n,1,n);
	for(int i=1;i<=(n>>1);++i)swap(a[i],a[n-i+1]),swap(f[i],f[n-i+1]);
	solve(1,n,1,n);
	for(int i=n;i;i--)write(ceil(f[i])-a[i]),putchar('\n');
	return 0;
}

