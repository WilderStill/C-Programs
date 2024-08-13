#include<bits/stdc++.h>
#define int long long
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
int a[11451411],maxdgts;
multiset<int>m;
vector<pair<int,int>>ans;
signed main()
{
	int n=read(),k=read();
	for(int i=1,j=1;i<=n;++i)
	{
		a[i]=read();
		m.insert(a[i]);
		while(*(m.rbegin())-*(m.begin())>k)m.erase(m.find(a[j++]));
		if(i-j+1>maxdgts)
		{
			ans.clear();
			maxdgts=i-j+1;
			ans.emplace_back(make_pair(j,i));
		}
		else if(i-j+1==maxdgts)ans.emplace_back(make_pair(j,i));
	}
	write(maxdgts),putchar(' '),write(ans.size()),puts("");
	for(auto syh:ans)write(syh.first),putchar(' '),write(syh.second),puts("");
	return 0;
}

