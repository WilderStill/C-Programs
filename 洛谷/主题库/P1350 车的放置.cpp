#include<bits/stdc++.h>
#define M 2020 
using namespace std;
const int mod=100003;
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
int f[M][M];
int main()
{
    int a=read(),b=read(),c=read(),d=read(),k=read();
    f[0][0]=1;
    for(int i=1;i<=a+c;++i)
        for(int j=0;j<=k;++j)
        {
        	if(!j)
        	{
        		f[i][k+1]=(i<=c)?d:d+b;
				f[i][j]=1;
			}
        	else f[i][j]=(f[i-1][j]+f[i-1][j-1]*(f[i][k+1]-j+1))%mod;
		} 
    write(f[a+c][k]);
    return 0;
}
