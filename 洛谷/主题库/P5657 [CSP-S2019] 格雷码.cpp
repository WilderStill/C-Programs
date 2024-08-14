#include<bits/stdc++.h>
using namespace std;
inline __int128 read()
{
    __int128 x=0,f=1;
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
inline void write(__int128 x)
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
__int128 n,k;
int main()
{
	n=read(),k=read();
    k^=k>>1;
    while(~--n)write(k>>n&1);
}

