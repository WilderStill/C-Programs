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
set<int>st;
int main()
{
	int n=read(),m=read();
	st.clear();
	for(int i=0;i<=n;++i)st.insert(i);
	for(int i=1;i<=m;++i)
	{
		int k=read();
		auto it=--st.upper_bound(k);
		if(!(*it))
		{
			write(i-1);
			return 0;
		}
		st.erase(it);
	}
	write(m);
    return 0;
}
