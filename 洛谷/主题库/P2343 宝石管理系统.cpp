#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
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
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+48);
	return;
}
vector<int>num;
int m,q;
int main()
{
	int m=read(),q=read();
	for(int i=1;i<=m;++i)num.push_back(-read());
	sort(num.begin(),num.end());
    for(int i=1;i<=q;++i)
    {
        int c=read(),n=-read();
        if(c==1)write(-num[-n-1]),puts("");
        else num.insert(upper_bound(num.begin(),num.end(),n),n);
    }
	return 0;
}
