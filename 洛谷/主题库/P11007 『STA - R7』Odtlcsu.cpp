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
int main()
{
	int n=read(),k=read(),tp=abs(k-n)/2;
	write(k),puts("");
	for(int i=1;i<=tp;++i)write(-1),putchar(' ');
	for(int i=1;i<=k-tp;++i)write(1),putchar(' ');
    return 0;
}

