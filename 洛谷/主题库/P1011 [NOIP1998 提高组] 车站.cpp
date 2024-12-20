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
int f[100010]={0,1};
int main()
{
    int a=read(),n=read(),m=read(),x=read();
    for(int i=2;i<n;++i)f[i]=f[i-1]+f[i-2];
    int t=(m-f[n-3]*a-a)/(f[n-2]-1);
    write(x==1?a:(f[x-2]+1)*a+(f[x-1]-1)*t);
    return 0;
}

