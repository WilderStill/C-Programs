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
struct interval
{
	int l,r;
	bool operator <(const interval&syh)const{return r<syh.l;}
};
set<interval>st;
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)
	{
		char op[2];
		scanf("%s",op);
		if(op[0]=='A')
		{
			int l=read(),r=read(),res=0;
			auto p=st.find({l,r});
			while(p!=st.end())
			{
				++res,st.erase(p);
				p=st.find({l,r});
			}
			st.insert({l,r});
			write(res),puts("");
		}
		else write(st.size()),puts("");
	}
	return 0;
}

