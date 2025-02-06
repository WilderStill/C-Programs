#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
inline int read()
{
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch<='9'&&ch>='0')
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x;
}
inline void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
const int M=3e5+10;
int n,m;
char s[M];
inline int lowbit(int x){return x&(-x);}
struct FenwickTree
{
	gp_hash_table<int,int>tr;
	inline void modify(int x,int v){for(int i=x;i<=n;i+=lowbit(i))tr[i]+=v;return;}
	inline int query(int x){int res=0;for(int i=x;i;i-=lowbit(i))res+=tr[i];return res;}
}dg[M];
set<int>q;
inline void Modify(int l,int r,int x,int v)
{
    for(int i=l+1;i<=n;i+=lowbit(i))dg[i].modify(x+1,v),dg[i].modify(r+1,-v);
    for(int i=x+1;i<=n;i+=lowbit(i))dg[i].modify(x+1,-v),dg[i].modify(r+1,v);
    return;
}
inline int Query(int x,int y,int v)
{
    int res=v;
    for(int i=x;i;i-=lowbit(i))res+=dg[i].query(y);
    return res;
}
int main()
{
	q.insert(0);
	n=read(),m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)if(s[i]=='0')q.insert(i);
	q.insert(++n);
	for(int i=1;i<=m;++i)
	{
        char op[6];
		scanf("%s",op);
		if(op[0]=='t')
		{
			int x=read();
			auto it=q.lower_bound(x);
			int l,r;
			if(*it!=x)
            {
                r=*it,l=*(--it);
                Modify(l,r,x,i);
                q.insert(x);
            }
			else
            {
                l=*(--it),++it,r=*(++it);
                Modify(l,r,x,-i);
                q.erase(x);
            }
		}
		else
		{
			int x=read(),y=read();
			auto it=q.lower_bound(x);
			write(Query(x,y,(*it>=y)?i:0));
			puts("");
		}
	}
    return 0;
}
