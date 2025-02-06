#include<bits/stdc++.h>
using namespace std;
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
int main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		string S;
		int len=0;
		for(int i=1;;++i)
		{
			S+=to_string(i);
			len+=S.size();
			if(len>=n)
			{
				len-=S.size();
				putchar(S[n-len-1]);
				puts("");
				break;
			}
		}
	}
} 
