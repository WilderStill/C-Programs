#include<bits/stdc++.h>
#define mod 100000
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
long long f[510][510];
bool bmod[201][201];
char s[510];
inline int bra(char lc,char rc)
{
	if(lc=='?'&&rc=='?')return 3;
	if(lc=='?'&&(rc==')'||rc==']'||rc=='}'))return 1;
	if(rc=='?'&&(lc=='('||lc=='['||lc=='{'))return 1;
	if(lc=='('&&rc==')'||lc=='['&&rc==']'||lc=='{'&&rc=='}')return 1;
	return 0;
}
int main()
{
	int n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)f[i][i-1]=1;
	for(int l=2;l<=n;l+=2)
	{
		for(int i=1,j=l+i-1;j<=n;++i,++j)
		{
			f[i][j]=bra(s[i],s[j])*f[i+1][j-1];
			if(f[i][j]>=mod)bmod[i][j]=1,f[i][j]%=mod;
			if(bra(s[i],s[j]))bmod[i][j]|=bmod[i+1][j-1];
			for(int k=i+1;k<j;k+=2)
			{
				if(bra(s[i],s[k]))
				{
					f[i][j]+=f[k+1][j]*f[i+1][k-1]*bra(s[i],s[k]);
					bmod[i][j]|=(bmod[i][k]|bmod[k+1][j]);
				}
				if(f[i][j]>=mod)bmod[i][j]=1,f[i][j]%=mod;
			}
		}
	}
	if(bmod[1][n])
	{
		int k=mod/10;
		while(k)
		{
			if(f[1][n]<k)putchar('0');
			else
			{
				write(f[1][n]);
				break;
			}
			k/=10;
		}
	}
	else write(f[1][n]);
}
