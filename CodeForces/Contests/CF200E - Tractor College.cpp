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
int main()
{
	int n=read(),s=read(),c3=0,c4=0,c5=0,ans3,ans4,ans5,res=INF;
	for(int i=1;i<=n;++i)
	{
		int x=read();
		if(x==3)++c3;
		if(x==4)++c4;
		if(x==5)++c5;
	}
	for(int k3=s/n;~k3;--k3)
	{    
		for(int k4=(s-c3*k3)/(n-c3);k4>=k3;--k4)
		{
			int k5=(s-c3*k3-c4*k4)/c5;
			if(k5*c5-k4*c4>=res)break;
			if(c3*k3+c4*k4+c5*k5==s&&k3<=k4&&k4<=k5)
			{
				int tp=abs(c3*k3-c4*k4)+abs(c4*k4-c5*k5);
				if(tp<res)res=tp,ans3=k3,ans4=k4,ans5=k5;
			}
		}
    }
	if(res^INF)
	{
		write(ans3),putchar(' ');
		write(ans4),putchar(' ');
		write(ans5),putchar(' ');
	}
	else puts("-1");
    return 0;
}

