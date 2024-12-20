#include<bits/stdc++.h>
using namespace std;
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
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
multiset<string>st;
int main()
{
	int x=read(),y=read(),z=read();
	for(int i=1;i<=x;++i)st.insert("a");
	for(int i=1;i<=y;++i)st.insert("b");
	for(int i=1;i<=z;++i)st.insert("c");
	while(st.size()>1)
	{
		auto l=st.begin(),r=st.end();
		st.insert(*l+*--r);
		st.erase(l),st.erase(r);
	}
	cout<<(*st.begin());
	return 0;
}

