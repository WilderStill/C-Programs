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
int f[4][1010];
int main()
{
	int k=read(),n1=read(),n2=read(),n3=read(),t1=read(),t2=read(),t3=read(),ans=0;
	for(int i=1;i<=k;++i)
	{
		ans=max({f[1][i%n1]+t1+t2+t3,f[2][i%n2]+t2+t3,f[3][i%n3]+t3});
		f[1][i%n1]=ans-t2-t3;
		f[2][i%n2]=ans-t3;
		f[3][i%n3]=ans;
	}
	write(ans);
    return 0;
}

