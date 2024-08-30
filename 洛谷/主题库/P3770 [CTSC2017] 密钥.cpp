#include<bits/stdc++.h>
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
int seed,n,k,S,tot,pos,syh;
int p[20000005],tp[20000005],sum[20000005],ans[20000005],buk[20000005];
int getrand()
{
	seed=((seed*12321)^9999)%32768;
	return seed;
}
void generateData()
{
	k=read(),seed=read(),S=read();
	int t=0;
	n=k*2+1;
	memset(p,0,sizeof p);
	for(int i=1;i<=n;++i)
	{
		p[i]=(getrand()/128)&1;
		t+=p[i];
	}
	int c=1;
	while(t>k)
	{
		while(!p[c])++c;
		p[c]=0;
		--t;
	}
	while(t<k)
	{
		while(p[c])++c;
		p[c]=1;
		++t;
	}
}
int ans1,ans2,ans3;
void checkans(int x)
{
	if(!tot)ans1=ans[x];
	if(tot==S)ans2=ans[x];
	if(tot==k-S)ans3=ans[x];
	if(ans1&&ans2&&ans3)
	{
		write(ans1),puts("");
		write(ans2),puts("");
		write(ans3),puts("\n");
		exit(0);
	}
}
int main()
{
	generateData();
	for(int i=1;i<=n;++i)
		if(!p[i])
		{
			pos=i;
			break;
		}
	for(int i=1;i<=n;++i)
	{
		ans[i]=pos;
		tp[i]=p[pos++];
		if(pos>n)pos-=n;
	}
	for(int i=2;i<=n;++i)sum[i]=sum[i-1]+(tp[i]?1:-1);
	for(int i=2;i<=n;++i)if(tp[i])++buk[sum[i]+k];
	for(int i=k+1;i<=(k<<1);++i)tot+=buk[i];
	checkans(1);
	syh=k;
	for(int i=2;i<=n;++i) 
		if(tp[i])tot-=buk[++syh],--buk[sum[i]+k],++buk[sum[i]+k-1];
		else tot+=buk[syh],--syh,checkans(i);
	return 0;
}

