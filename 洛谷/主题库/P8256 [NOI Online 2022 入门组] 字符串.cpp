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
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
const int mod=1000000007;
int f[410][410][410];
char s[410],t[410];
int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),m=read();
		scanf("%s%s",s+1,t+1);
		int len=0,cnt=0;
		for(int i=1;i<=n;++i)if(s[i]=='-')++cnt;
		if(n-2*cnt!=m)
		{
			puts("0");
			continue;
		}
		memset(f,0,sizeof f);
		f[0][0][0]=1;
		for(int i=1;i<=n;++i)
		{
			s[i]=='-'?--len:++len;
			for(int j=0;j<=cnt;++j)
				for(int k=0;k<=cnt;++k)
				{
					if(s[i]=='-')f[i][j][k]=(f[i-1][j+1][k]+f[i-1][j][k+1])%mod;
					else
					{
						if(k>0)f[i][j][k]=f[i-1][j][k-1];
						else if(t[len-j]==s[i])f[i][j][k]=f[i-1][j][k]; 
						if(len==j)(f[i][j][k]+=f[i-1][j-1][k])%=mod;
					}
				}
		}	
		write(f[n][0][0]);
		puts("");
	}
	return 0;
}
