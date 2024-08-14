#include<bits/stdc++.h>
#define qhd deq[hd]
#define qtl deq[tl]
#define db double
#define M 114514
#define eps 1e-10
using namespace std;
int n,s,t,b[M],deq[M];
db a[M],sum[M];
bool check(double x)
{
    int hd=1,tl=0;
    for(int i=1;i<=n;++i)a[i]=b[i]*1.0-x;
    sum[0]=0;
    for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;++i)
	{
        if(i>=s)
		{
            while(tl>=hd&&sum[i-s]<sum[qtl])--tl;
            ++tl;
            qtl=i-s;
        }
        if(hd<=tl&&qhd<i-t)++hd;
        if(hd<=tl&&sum[i]-sum[qhd]>=0)return 1;
    }
    return 0;
}
int main()
{
    scanf("%d%d%d",&n,&s,&t);
    for(int i=1;i<=n;++i)scanf("%d",&b[i]);
    db l=-M,r=M;
    while(r-l>eps)
	{
        db mid=(l+r)/2;
        if(check(mid))l=mid;
        else r=mid;
    }
    printf("%.3lf",l);
    return 0;
}
