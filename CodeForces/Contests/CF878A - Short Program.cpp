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
int x=1023,y=0;
int main()
{
    int n=read();
    for(int t=1;t<=n;++t) 
	{
        char c[2];
        scanf("%s",c+1);
        int k=read();
        if(c[1]=='|')x|=k,y|=k;
        if(c[1]=='&')x&=k,y&=k;
        if(c[1]=='^')x^=k,y^=k;
    }
    write(2),putchar('\n');
	putchar('|'),putchar(' '),write(x^y^1023),putchar('\n');
	putchar('^'),putchar(' '),write(x^1023),putchar('\n');
    return 0;
}
