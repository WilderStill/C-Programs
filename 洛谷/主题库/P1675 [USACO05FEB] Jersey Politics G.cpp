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
inline void file()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}
struct node
{
	int pos,val;
	bool operator<(node b)
	{
		return val<b.val;
	}
}cow[200];
mt19937 dg(time(0));
int main()
{
    int k=read();
    for(int i=1;i<=k*3;++i)cow[i]={i,read()};
    sort(cow+1,cow+k*3+1);
    while(true)
    {
        shuffle(cow+k+2,cow+k*3+1,dg);
        int sum1=0,sum2=0;
        bool fg1=0,fg2=0;
        for(int i=k+1;i<=2*k;++i)
        {
            sum1+=cow[i].val;
            if(sum1>500*k)
			{
				fg1=1;
				break;
			}
        }
        for(int i=k*2+1;i<=k*3;++i)
        {
            sum2+=cow[i].val;
            if(sum2>500*k)
			{
				fg2=1;
				break;
			}
        }
        if(fg1&&fg2)break;
        if(1.0*clock()/CLOCKS_PER_SEC>=0.95)break;
    }
    for(int i=1;i<=k*3;++i)write(cow[i].pos),puts("");
    return 0;
}

