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
int n,a,b,st,ed,sum,d[2010];
char ans[2010];
bitset<3600100>f[2010];
int main()
{
	n=read(),a=read(),b=read();
	st=a+b,ed=a-b;
	for(int i=1;i<=n;++i)d[i]=read(),sum+=d[i];
	if(abs(st)>sum||abs(ed)>sum||(st+sum)&1||(ed+sum)&1)
	{
		puts("No");
		return 0;
	}
	st=(st+sum)>>1,ed=(ed+sum)>>1;
	f[0][0]=1;
	for(int i=1;i<=n;++i)f[i]=f[i-1]|(f[i-1]<<d[i]);
	if(!f[n][st]||!f[n][ed])
	{
		puts("No");
		return 0;
	}
	for(int i=n;i;--i)
	{
		if(!f[i-1][st])
		{
			if(!f[i-1][ed])st-=d[i],ed-=d[i],ans[i]='R';
			else st-=d[i],ans[i]='U';
		}
		else
		{
			if(!f[i-1][ed])ed-=d[i],ans[i]='D';
			else ans[i]='L';
		}
	}
	puts("Yes");
	puts(ans+1);
    return 0;
}

