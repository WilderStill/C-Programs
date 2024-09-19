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
int n,ans=INF,num[1010];
inline int calc()
{
    int s1=0,s2=0;
    for(int i=1;i<=(n+1)/2;++i)s1+=num[i];
    for(int i=(n+1)/2+1;i<=n;++i)s2+=num[i];
    return abs(s1-s2);
}
inline void Dg()
{
	double t=2000;
	while(t>1e-10)
	{
		int x=rand()%n+1,y=rand()%n+1;
        swap(num[x],num[y]);
        int res=calc();
        if(res<ans)ans=res;
		else if(exp((ans-res)/t)<(double)rand()/RAND_MAX)swap(num[x],num[y]);
		t*=0.9112;
	}
}
int main()
{
	srand(time(0));
    int T=read();
    while(T--)
    {
        n=read();
    	for(int i=1;i<=n;++i)num[i]=read();
    	int test=100;
        while(test--)Dg();
        write(ans);
        puts("");
        ans=INF;
    }
}
