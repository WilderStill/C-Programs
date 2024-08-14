#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int mod=1000000007;
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
}
char s[510];
int f[510][510][6];
signed main()
{
	
	int n=read(),K=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)f[i][i-1][0]=1;
	for(int l=1;l<=n;++l)
	{
		for(int i=1,j=i+l-1;j<=n;++i,++j)
		{
			if(l<=K)f[i][j][0]=f[i][j-1][0]&&(s[j]=='*'||s[j]=='?');
			if(l>=2)
			{
				if((s[i]=='('||s[i]=='?')&&(s[j]==')'||s[j]=='?'))
					f[i][j][1]=(f[i+1][j-1][0]+f[i+1][j-1][2]+f[i+1][j-1][3]+f[i+1][j-1][4])%mod;
				for(int k=i;k<j;++k)
				{
					(f[i][j][2]+=f[i][k][3]*f[k+1][j][0])%=mod;
					(f[i][j][3]+=(f[i][k][2]+f[i][k][3])*f[k+1][j][1])%=mod;
					(f[i][j][4]+=(f[i][k][4]+f[i][k][5])*f[k+1][j][1])%=mod;
					(f[i][j][5]+=f[i][k][4]*f[k+1][j][0])%=mod;
				}
			}
			(f[i][j][5]+=f[i][j][0])%=mod;
			(f[i][j][3]+=f[i][j][1])%=mod;
		}
	}
	write(f[1][n][3]%mod);
    return 0;
}
