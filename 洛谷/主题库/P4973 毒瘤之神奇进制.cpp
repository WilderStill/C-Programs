#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
inline ll read()
{
	ll x=0,f=1;
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
inline void write(ll x)
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
char s[100010];
int main()
{
	ll T=read();
	while(T--)
	{
		ll n=read();
		scanf("%s",s+1);
		ll len=strlen(s+1);
		ld ans=0;
		for(int i=1;i<=len;++i)ans+=log10(abs(s[i]-'0'));
		ans+=0.5*len*(len-1)*log10(n);
		write(ans+1),puts("");
	}
	return 0;
}
