#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
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
int n,k,ans1,a[500010],qmax[500010][25],qmin[500010][25];
inline int querymax(int l,int r)
{
    if(l>r)return -1ll*INF;
    int k=log2(r-l+1);
    return max(qmax[l][k],qmax[r-(1<<k)+1][k]);
}
inline int querymin(int l,int r)
{
    if(l>r)return 1ll*INF;
    int k=log2(r-l+1);
    return min(qmin[l][k],qmin[r-(1<<k)+1][k]);
}
inline bool check(int x)
{
    int sum=0;
    for(int i=1;i<=n-x+1;++i)
        if(querymax(i,i+x-1)-querymin(i,i+x-1)>=ans1)++sum;
	return sum<k;
}
signed main()
{
    int T=read();
	while(T--)
	{
        n=read(),k=read(),ans1=INF;
        for(int i=1;i<=n;++i)a[i]=read();
        for(int i=1;i<=n;++i)qmax[i][0]=qmin[i][0]=a[i];
	    for(int j=1;j<25;++j)
	        for(int i=0;i+(1<<j)-1<=n;++i)
	            qmax[i][j]=max(qmax[i][j-1],qmax[i+(1<<(j-1))][j-1]),qmin[i][j]=min(qmin[i][j-1],qmin[i+(1<<(j-1))][j-1]);
        for(int i=1;i<=k;++i)ans1=min(ans1,querymax(i,n-k+i)-querymin(i,n-k+i));
        write(ans1),putchar(' ');
		int l=1,r=n-k+1,ans2;
        while(l<=r)
		{
            int mid=(l+r)>>1;
            if(check(mid))l=mid+1;
            else r=mid-1,ans2=mid;
        }
		write(ans2),puts("");
    }
	return 0;
}
