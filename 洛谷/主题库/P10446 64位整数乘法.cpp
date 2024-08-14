#include<bits/stdc++.h>
using namespace std;
inline __int128 read()
{
	__int128 x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		ch=getchar();
		if(ch=='-')f=-1; 
	}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
inline void print(__int128 x)
{
	if(x>=10) print(x/10);
	putchar(x%10+'0');
}
int main()
{
	__int128 a,b,c;
	a=read(),b=read(),c=read();
	print(a*b%c);
	return 0;
}
