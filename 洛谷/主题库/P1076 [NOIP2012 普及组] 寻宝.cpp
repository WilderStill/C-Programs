#include<bits/stdc++.h>
#define mod 20123
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
int st[10010][110],cnt[10010],num[10010][110];
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			st[i][j]=read(),num[i][j]=read();
			if(st[i][j])++cnt[i];
		}
	int pos=read()+1,ans=0;
	for(int i=1;i<=n;++i)
	{
		(ans+=num[i][pos])%=mod;
		int tp=(num[i][pos])%cnt[i]+cnt[i];
		pos--;
		while(tp)
		{
			if(++pos>m)pos=1;
			if(st[i][pos])--tp;
		}
	}
	write(ans);
	return 0;
}

