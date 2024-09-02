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
bitset<M>st,tp;
int main()
{
	tp.set();
	int n=read(),m=read();
	for(int i=1;i<=m;++i)
	{
		int op=read(),l=read(),r=read(),len=r-l+1;
		if(!op)st^=((tp>>(M-len))<<(l-1));
		else write((st&((tp>>(M-len))<<(l-1))).count()),puts("");
	}
    return 0;
}

