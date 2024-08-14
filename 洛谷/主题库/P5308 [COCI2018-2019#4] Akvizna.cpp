#include<bits/stdc++.h>
#define ld long double
using namespace std;
const ld eps=1e-18;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	return x*f;
}
ld f[100010];
int n,K,pos=0,hd=1,tl=1,q[100010],cnt[100010];
ld X(int i1)
{
	return (ld)(i1);
}
ld Y(int i1)
{
	return f[i1];
}
ld kk(int i1,int i2)
{
	return (ld)((ld)(Y(i1)-Y(i2)))/((ld)(X(i1)-X(i2)));
}
bool check(ld x)
{
	hd=1,tl=1;
	q[1]=0;
    for(int i=1;i<=n;++i)
    {
    	while(hd<tl&&kk(q[hd],q[hd+1])-1.0/i>eps)++hd;
        f[i]=f[q[hd]]+(ld)(i-q[hd])/i-x;
        cnt[i]=cnt[q[hd]]+1;
        while(hd<tl&&kk(q[tl-1],q[tl])+eps<kk(q[tl],i))--tl;
        q[++tl]=i;
    }
    return cnt[n]>=K;
}
int main()
{
	n=read(),K=read();
	ld l=0,r=1e6,mid;
	while(r-l>eps)
	{
		mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	mid=l;
	check(mid);
	printf("%.9Lf",f[n]+K*mid);
    return 0;
}
