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
int n,m,st[300010][63];
inline int query(int l,int r)
{
	int len=(r-l+1),lg=log2(len);
	return max(st[l][lg],st[r-(1<<lg)+1][lg]);
}
inline bool check(int x,int t,int i)
{
	return max(query(i-t,i-1),query(i+1,i+t))<x;
} 
inline int solve(int x,int i)
{
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(x,mid,i))l=mid+1;
		else r=mid;
	}
	return l==n?-1:l;
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)st[i][0]=st[i+n][0]=st[i+(n<<1)][0]=read();
	for(int j=1;j<=log2(3*n);++j)
		for(int i=1;i+(1<<j)-1<=3*n;++i)
			st[i][j]=max(st[i][j-1],st[i+(1<<j-1)][j-1]);
	for(int i=1;i<=n;++i)
		write(solve(read(),i+n)),putchar(' ');
    return 0;
}

