#include<bits/stdc++.h>
#define ll long long
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
inline void write(ll x)
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
char mp[3010][3010];
int ocnt[3010][3010],icnt[3010][3010];
int main()
{
	int n=read(),m=read();
	ll ans=0;
	for(int i=1;i<=n;++i)
		scanf("%s",mp[i]+1);
	for(int i=1;i<=m;++i)
	{
		int sum=0;
		for(int j=n;j;--j)
		{
			sum+=(mp[j][i]=='I');
			icnt[i][j]=sum;
		}
	}
	for(int i=1;i<=n;++i)
	{
		int sum=0;
		for(int j=m;j;--j)
		{
			sum+=(mp[i][j]=='O');
			ocnt[i][j]=sum;
		}	
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(mp[i][j]=='J')
				ans+=(ocnt[i][j]*icnt[j][i]);
	write(ans);
	return 0;
}
