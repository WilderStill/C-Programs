#include<bits/stdc++.h>
#define M 100010
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
int ansa[M],ansb[M],num[M];
int main()
{
	int n=read();
	if(n&1)
	{
		for(int i=0;i<n;++i)
		{
			ansa[(i<<1|1)%n]=i;
			ansb[(i<<1|1)%n]=(i+1)%n;
		}
		for(int i=1;i<=n;++i)num[i]=read();
		for(int i=1;i<=n;++i)write(ansa[num[i]]),putchar(' ');puts("");
		for(int i=1;i<=n;++i)write(ansb[num[i]]),putchar(' ');puts("");
	} 
	else puts("-1");
    return 0;
}

