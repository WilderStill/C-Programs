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
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
const int INF=0x3f3f3f3f;
int ans;
set<int>s;
inline void find(int x)
{
    auto l=--s.lower_bound(x),r=s.lower_bound(x);
    if(x-*l<=*r-x&&*l!=-INF)
	{
        ans+=x-*l;
        s.erase(l);
    }
	else
	{
        ans+=*r-x;
        s.erase(r);
    }
    ans%=1000000;
}
int main()
{
    int n=read(),pet;
    s.insert(-INF),s.insert(INF);
    for(int i=1;i<=n;++i)
	{
        int a=read(),b=read();
        if(s.size()==2)
		{
            pet=a;
            s.insert(b);
        }
		else if(a==pet)s.insert(b);
        else find(b);
    }
    write(ans);
    return 0;
}
