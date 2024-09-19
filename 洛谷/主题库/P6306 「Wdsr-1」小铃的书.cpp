#include<bits/stdc++.h>
#define uint unsigned int
#define ll long long
#define ull unsigned long long
using namespace std;
inline int read()
{
    int x=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x;
}
inline ull readl()
{
    ull x=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))
	{
        x=(x<<1ull)+(x<<3ull)+(ch&15);
        ch=getchar();
    }
    return x;
}
inline void write(ull x)
{
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
const int Base=1<<16;
int cnt[16][Base];
ull ans;
int main()
{
	int n=read(),k=read();
	for(int t=1;t<=n;++t)
	{
		ull x=readl();
		for(int i=0;i<16;++i)
			cnt[i][((1<<16)-1)&x]++,x>>=4;
	}
	for(ull i=0;i<16;++i)
		for(ull j=0;j<Base;++j)
			if(cnt[i][j]%k==1)ans|=j<<(i*4ull);
	write(ans);
	return 0;
}
