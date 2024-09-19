#include<bits/stdc++.h>
#define int long long
#define M 200010
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
int num[M],qmax[M][25];
inline int querymax(int l,int r)
{
    int k=log2(r-l+1);
    return max(qmax[l][k],qmax[r-(1<<k)+1][k]);
}
signed main()
{
	int n=read(),q=read();
	for(int i=1;i<=n;++i)
		qmax[i][0]=num[i]=read();
	for(int j=1;j<25;++j)
	    for(int i=0;i+(1<<j)-1<=n;++i)
	        qmax[i][j]=max(qmax[i][j-1],qmax[i+(1<<(j-1))][j-1]);
	for(int i=1;i<=q;++i)
	{
		int l=read(),r=read();
		if(l>r)swap(l,r);
		write(querymax(l,r));
		puts("");
	}
	return 0;
}
