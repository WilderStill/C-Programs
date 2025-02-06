#include<bits/stdc++.h>
#define M 2000010
using namespace std;
char input[M],str[M];
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch&15);
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
	putchar(x%10+'0');
	return;
}
inline int get_input()
{
	char ch=getchar();
	int len=0;
	while(!islower(ch))ch=getchar();
	while(islower(ch))input[++len]=ch,ch=getchar();
	return len;
}
inline int getstr(int rawlen)
{
	int cnt=0;
	str[cnt]='*';
	str[++cnt]='$';
	for(int i=1;i<=rawlen;++i)
	{
		str[++cnt]=input[i];
		str[++cnt]='$';
	}
	str[cnt+1]='%';
	return cnt;
}
int plen[M];
bool vis[M];
inline void manacher(int len)
{
	int pos=0,maxn=0;
	for(int i=1;i<=len;++i)
	{
		if(i<=maxn)plen[i]=min(maxn-i,plen[pos*2-i]);
		while(str[i+plen[i]]==str[i-plen[i]])++plen[i];
		if(plen[i]+i>maxn)maxn=plen[i]+i-1,pos=i;
	}
}
int main()
{
	int T=read();
	while(T--)
	{
		memset(vis,0,sizeof vis);
		memset(plen,0,sizeof plen);
		int inlen=get_input();
		int len=getstr(inlen);
		manacher(len);
		for(int i=len;i;--i)
		{
			if(i+plen[i]-1==len)vis[i]=1;
			else if(vis[i+plen[i]-2]&&i==plen[i])vis[i]=1;
		}
		for(int i=1;i<=len;++i)if(islower(str[i])&&vis[i])write(i>>1),putchar(' ');
		puts("");
	}
	return 0;
}
