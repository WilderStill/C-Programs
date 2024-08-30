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
int a[100010],ans[100010],sum[100010],qmax[100010][25],qmin[100010][25];
inline void solve(int l,int r,int L,int R)
{
	auto querymax=[](int l,int r)
	{
	    if(l>r)return -1ll*INF;
	    int k=log2(r-l+1);
	    return max(qmax[l][k],qmax[r-(1<<k)+1][k]);
	};
	auto querymin=[](int l,int r)
	{
	    if(l>r)return 1ll*INF;
	    int k=log2(r-l+1);
	    return min(qmin[l][k],qmin[r-(1<<k)+1][k]);
	};
	if(r-l+1<L)return;
    if(l==r&&L==1)
	{
        ans[l]=max(ans[l],a[l]);
        return;
    }
    int mid=(l+r)>>1;
    solve(l,mid,L,R);
	solve(mid+1,r,L,R);
    int res=-INF;
    for(int i=l;i<=mid;++i)
	{
        int tl=max(mid+1,i+L-1),tr=min(r,i+R-1);
        res=max(res,querymax(tl,tr)-sum[i-1]);
        ans[i]=max(ans[i],res);
    }
    res=-INF;
    for(int i=r;i>mid;--i)
	{
		int tl=max(l-1,i-R),tr=min(mid,i-L);
        res=max(res,sum[i]-querymin(tl,tr));
        ans[i]=max(ans[i],res);
    }
}
signed main()
{
	int n=read(),l=read(),r=read();
	memset(ans,-INF,sizeof ans);
	for(int i=1;i<=n;++i)a[i]=read(),sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;++i)qmax[i][0]=qmin[i][0]=sum[i];
    for(int j=1;j<25;++j)
        for(int i=0;i+(1<<j)-1<=n;++i)
            qmax[i][j]=max(qmax[i][j-1],qmax[i+(1<<(j-1))][j-1]),qmin[i][j]=min(qmin[i][j-1],qmin[i+(1<<(j-1))][j-1]);
    solve(1,n,l,r);
    for(int i=1;i<=n;++i)write(ans[i]),putchar(' ');
	return 0;
}

