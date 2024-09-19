#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define INF 0x3f3f3f3f
using namespace std;
using namespace __gnu_pbds;
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
map<char,tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>>mp;
inline int solve(char x,char y,char z)
{
	if(mp[z].empty())return mp[x].size();
	if(mp[y].empty())return 0;
	int l_win=mp[x].order_of_key(*mp[y].begin()),l_lose=mp[x].order_of_key(*mp[z].begin()),r_win=mp[x].order_of_key(*mp[y].rbegin()),r_lose=mp[x].order_of_key(*mp[z].rbegin());
	return mp[x].size()-max(0,r_lose-r_win)-max(0,l_win-l_lose);
}
char s[200010];
int main()
{
	int n=read(),q=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)mp[s[i]].insert(i);
	write(solve('R','S','P')+solve('P','R','S')+solve('S','P','R')),puts("");
	for(int i=1;i<=q;++i)
	{
		char val[2],ch;
		int x=read();
		scanf("%s",val);
		ch=val[0];
		mp[s[x]].erase(x);
		mp[s[x]=ch].insert(x);
		write(solve('R','S','P')+solve('P','R','S')+solve('S','P','R')),puts("");
	}
}
