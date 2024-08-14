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
set<int>num;
int main()
{
	int T=read();
	while(T--)
	{
		num.clear();
		int n=read();
		for(int i=1;i<=n;++i)num.insert(read());
		if(num.size()==1)write(n);
		else write(n-1);
		puts("");
	}
    return 0;
}

