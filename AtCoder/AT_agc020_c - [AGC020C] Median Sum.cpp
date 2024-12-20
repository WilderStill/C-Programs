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
bitset<4000000>f;
int main()
{
	int n=read(),sum=0;
	f[0]=1;
	for(int i=1;i<=n;++i)
	{
		int x=read();
		f|=f<<x;
		sum+=x;
	}
	for(int i=sum+1>>1;i<=sum;++i)
		if(f[i])
		{
			write(i);
			return 0;
		}
	return 0;
}

