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
inline void file()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}
int n;
vector<pair<int,int>>ans;
void fill_3x3(int x,int y)
{
	ans.push_back(make_pair(x,y+1));
	ans.push_back(make_pair(x+1,y-1));
	ans.push_back(make_pair(x,y));
	ans.push_back(make_pair(x-1,y-1));
	ans.push_back(make_pair(x+1,y+1));
	ans.push_back(make_pair(x+1,y));
	ans.push_back(make_pair(x-1,y));
	ans.push_back(make_pair(x-1,y+1));
}
inline void dfs1a(int l,int r)
{
	if(l==r)return;
	int mid=(l+r)/2;
	for(int i=l+1;i<mid;++i)
	{
		ans.push_back(make_pair(i,l));
		ans.push_back(make_pair(r-i+l,r));
		ans.push_back(make_pair(n-i+1,l));
		ans.push_back(make_pair(i,r));
	}
	for(int i=l+1;i<mid;++i)
	{
		ans.push_back(make_pair(l,i));
		ans.push_back(make_pair(r,r-i+l));
		ans.push_back(make_pair(l,r-i+l));
		ans.push_back(make_pair(r,i));
	}
	dfs1a(l+1,r-1);
}
inline void dfs1b(int l,int r)
{
	if(l+2==r)return;
	int mid=(l+r)>>1;
	ans.push_back(make_pair(mid,l));
	ans.push_back(make_pair(l,mid));
	ans.push_back(make_pair(mid,r));
	ans.push_back(make_pair(r,l));
	ans.push_back(make_pair(l,l));
	ans.push_back(make_pair(r,r));
	ans.push_back(make_pair(l,r));
	ans.push_back(make_pair(r,mid));
	dfs1b(l+1,r-1);
}
inline void dfs2a(int l,int r)
{
	if(l+3==r)return;
	int mid=(l+r-1)/2;
	for(int i=l;i<r-2;++i,++i)
	{
		ans.push_back(make_pair(l,i));
		ans.push_back(make_pair(r,i+1));
		ans.push_back(make_pair(l,i+1));
		ans.push_back(make_pair(r,i));
	}
	ans.push_back(make_pair(l,r-1));
	ans.push_back(make_pair(l,r));
	ans.push_back(make_pair(r,r));
	ans.push_back(make_pair(r,r-1));
	for(int i=l+1;i<=mid;++i)
	{
		ans.push_back(make_pair(i,l));
		ans.push_back(make_pair(r-i+l,r));
		ans.push_back(make_pair(r-i+l,l));
		ans.push_back(make_pair(i,r));
	}
	dfs2a(l+1,r-1);
}
inline void dfs2b(int l)
{
	ans.push_back(make_pair(l+1,l+1));
	ans.push_back(make_pair(l+4,l+2));
	ans.push_back(make_pair(l+4,l+4));
	ans.push_back(make_pair(l+3,l+1));
	ans.push_back(make_pair(l+2,l+1));
	ans.push_back(make_pair(l+4,l+3));
}
inline void solve()
{
	if(n&1)
	{
		dfs1a(1,n);
		int mid=(n+1)/2;
		fill_3x3(mid,mid);
		dfs1b(1,n);
		ans.push_back(make_pair(mid,mid-1));
	}
	else
	{
		dfs2a(1,n);
		int mid=n/2;
		fill_3x3(mid,mid+1);
		dfs2b(mid-2);
	}
}
int main()
{
	n=read();
	if(n<=2)
	{
		write(1),puts("");
		write(1),putchar(' '),write(1),puts("");
		return 0;
	}
	if(n&1)write(n*n),puts("");
	else write(n*n-2),puts("");
	solve();
	for(auto inv:ans)
	{
		write(inv.first),putchar(' ');
		write(inv.second),puts("");
	}
    return cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n',0;
}
