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
int cnt,l[1000100],r[1000100];
int main()
{
    int n=read();
    for(int i=1;i<=n;++i)
	{
    	++l[read()];
		++r[read()];
    }
    for(int i=1;i<1000100;++i)
	{
        if(!cnt&&l[i])write(i),putchar(' ');
        cnt+=l[i]-r[i];
        if(!cnt&&r[i])write(i),putchar('\n');
    }
    return 0;
}
