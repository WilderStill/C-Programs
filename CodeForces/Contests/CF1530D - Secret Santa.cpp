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
map<int,int>mp;
int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),cnt=0;
		vector<int>ans(n+1),p(n+1),ind(n+1),v;
        for(int i=1;i<=n;++i)
		{
            p[i]=read();
            ++ind[p[i]];
            mp[p[i]]=i;
        }
        for(int i=1;i<=n;++i)if(!ind[i])v.push_back(i);
        for(int i=1;i<=n;++i)
		{
            if(ind[p[i]]==1)ans[i]=p[i],++cnt;
            else
			{
                ans[i]=v.back();
                ind[p[i]]--;
                v.pop_back();
            }
        }
        write(cnt);
		putchar('\n');
        for(int i=1;i<=n;++i)
		{
            if(i-1)printf(" ");
            if(i==ans[i])
			{
                ans[i]=p[i];
                ans[mp[p[i]]]=i;
                mp[p[i]]=i;
            }
            write(ans[i]);
        }
        putchar('\n');
	}
	return 0;
}

