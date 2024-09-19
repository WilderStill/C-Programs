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
int n,m,ans=INF,maxn=-INF,minn=INF,matrix[2010][2010];
inline void reverse_matrix(int op)
{
	for(int i=1;i<=(op?n:(n/2));++i)
		for(int j=1;j<=(op?(m/2):m);++j)
			swap(matrix[i][j],(op?matrix[i][m-j+1]:matrix[n-i+1][j]));
}
inline bool check(int x)
{
	int res=m;
	for(int i=1;i<=n;++i)
	{
		int pos=0;
		for(int j=1;j<=res;++j)
		{
			if(maxn-matrix[i][j]>x)break;
			++pos;
		}
		res=pos;
		for(int j=pos+1;j<=m;++j)
			if(matrix[i][j]-minn>x)
				return 1;
	}
	return 0;
}
inline void solve()
{
	int l=0,r=maxn-minn+1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid;
	}
	ans=min(l,ans);
	return;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			matrix[i][j]=read(),maxn=max(maxn,matrix[i][j]),minn=min(minn,matrix[i][j]);
	for(int i=1;i<=4;++i)
	{
		reverse_matrix(i&1);
		solve();
	}
	write(ans);
	return 0;
}
