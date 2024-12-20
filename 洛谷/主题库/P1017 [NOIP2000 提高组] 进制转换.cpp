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
char num[100010];
int main()
{
	int n=read(),m=read(),cnt=0;
	write(n),putchar('=');
	while(n)
	{
		int t=n%m;
		n/=m;
		if(t<0)t-=m,++n;
		if(t<10)num[++cnt]=t+48;
		else num[++cnt]=t+55;
	}
	for(int i=cnt;i;--i)putchar(num[i]);
	putchar('(');
	putchar('b');
	putchar('a');
	putchar('s');
	putchar('e');
	write(m);
	putchar(')');
	return 0;
}
