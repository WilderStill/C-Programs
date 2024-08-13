#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
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
int n,f[1101010];
char s[1001010];
int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	f[0]=1;
	for(int i=1;i<=n;++i)
	{
		if((s[i]=='u'&&s[i-1]=='u')||(s[i]=='n'&&s[i-1]=='n'))f[i]=(f[i-2]+f[i])%mod;
		if(s[i]=='m'||s[i]=='w')
		{
			f[n]=0;break;
		}
		f[i]=(f[i]+f[i-1])%mod;
	}
	printf("%d",f[n]);
	return 0;
}

