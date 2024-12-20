#include<bits/stdc++.h>
#define int long long
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
inline int solve(int n)
{ 
    int cnt=0,res=0; 
    for(int i=2;i*i<=n;++i)
        if(!(n%i))
        {
        	++cnt;
        	int tp=1;
        	while(!(n%i))n/=i,tp*=i;
			res+=tp;
		}
    if(n>1)++cnt,res+=n;
    return res+(cnt==1);
}
signed main()
{
	int cases=0;
	while(true)
	{
		int n=read();
		if(!n)return 0;
		printf("Case ");
		write(++cases);
		printf(": ");
		write(n==1?2:solve(n));
		puts("");
	}
	return 0;
}
