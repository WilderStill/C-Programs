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
inline void write(long long x)
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
string s;
vector<int>ed;
int main()
{
	int T=read();
	while(T--)
	{
		ed.clear();
		cin>>s;
		int n=s.size();
		if(count(s.begin(),s.end(),'a')==n)
		{
			write(n-1);
			puts("");
			continue;
		}
		for(int i=0;i<n;++i)
			if(s[i]!='a')
				ed.push_back(i);
		int m=ed.size();
		long long ans=0;
		for(int i=1;i<=m;++i)
		{
			if(m%i)continue;
			bool fg=0;
			for(int j=i;j<m;++j)
			{
				int tmp=j%i;
				if(s[ed[j]]!=s[ed[tmp]]||(tmp&&ed[tmp]-ed[tmp-1]!=ed[j]-ed[j-1]))
				{
					fg=1;
					break;
				}
			}
			if(!fg)
			{
				int minn=n;
				for(int j=i;j<m;j+=i)
					minn=min(minn,ed[j]-ed[j-1]-1);
				int r=n-ed.back()-1;
				for(int l=0;l<=ed[0];++l)
					ans+=max(0,min(r+1,minn-l+1));
			}
		}
		write(ans);
		puts("");
	}
	return 0;
}

