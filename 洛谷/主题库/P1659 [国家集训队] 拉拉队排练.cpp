#include<bits/stdc++.h>
#define int long long
#define M 2000010
using namespace std;
const int mod=19930726;
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
inline int qpow(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1)res=(res*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return res%mod;
}
int plen[M],cnt[M];
inline void manacher(int len)
{
	int pos=0,maxn=0;
	for(int i=1;i<=len;++i)
	{
		if(i<=maxn)plen[i]=min(maxn-i,plen[(pos<<1)-i]);
		while(str[i+plen[i]]==str[i-plen[i]])++plen[i];
		if(plen[i]+i>maxn)maxn=plen[i]+i-1,pos=i;
		if((plen[i]-1)&1)++cnt[plen[i]-1];
	}
}
signed main()
{
	int n=read(),K=read();
	int inlen=get_input();
	int len=getstr(inlen);
	manacher(len);
	int ans=1,sum=0;
	for(int i=n;i;--i)
	{
		if(!(i&1))continue;
		sum+=cnt[i];
		if(sum<=K)
		{
			ans=(ans*qpow(i,sum))%mod;
			K-=sum;
		}
		else
		{
			ans=(ans*qpow(i,K))%mod;
			K-=sum;
			break;
		}
	}
	write(K<=0?ans:-1);
	return 0;
}
