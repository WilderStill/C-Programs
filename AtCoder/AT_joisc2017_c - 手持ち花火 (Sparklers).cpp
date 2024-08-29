#include<bits/stdc++.h>
#define ll long long
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
int n,k,t,tx[200010];
ll tp[200010];
int check(int x)
{
	auto run=[](int &l,int &r,int d)
	{
		auto valid=[](int pos){return pos>=1&&pos<=n;};
		int tl=0,tr=0;
		while(tl^l||tr^r)
		{
			int pl=tl=l,pr=tr=r;
			while(valid(pl-d)&&tp[pl-d]>=tp[r])if(tp[pl-=d]>=tp[l])l=pl;
			while(valid(pr+d)&&tp[pr+d]<=tp[l])if(tp[pr+=d]<=tp[r])r=pr;
		}
	};
	for(int i=1;i<=n;++i)tp[i]=tx[i]-2ll*x*t*i;
	if(tp[1]<tp[n])return 1;
	int l1=k,r1=k,l2=1,r2=n;
	run(l1,r1,1),run(l2,r2,-1);
	return l1>l2||r1<r2;
}
int main()
{
	n=read(),k=read(),t=read();
	for(int i=1;i<=n;++i)tx[i]=read();
	int l=0,r=tx[n]-tx[1];
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	write(r+1);
	puts("");
	return 0;
}
