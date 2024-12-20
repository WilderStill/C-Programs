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
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
int x[1010][2],y[1010][2],ans[2];
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			int t=read();
			x[i][j&1]+=t;
			y[j][i&1]+=t;
		}
	for(int i=1;i<=n;++i)
	{
		ans[0]+=max(x[i][1],x[i][0]);
		ans[1]+=max(y[i][1],y[i][0]);
	}
	write(max(ans[0],ans[1]));
	return 0;
}
