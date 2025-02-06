#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while((ch<48)|(ch>57)){if(ch=='-')f=-1;ch=getchar();}
	while((ch>=48)&(ch<=57))x=(x<<3)+(x<<1)+(ch&15),ch=getchar();
	return x*f;
}
inline void write(int x)
{
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
struct point{int x,y;}p[1000010];
struct node
{
    int val,id;
    bool operator<(node b)const{return b.val^val?b.val<val:b.id>id;}
};
priority_queue<node>q;
inline int sqr(int x){return x*x;}
signed main()
{
    int n=read();
	for(int i=1;i<=n;++i)p[i]={read(),read()};
	int m=read();
	for(int i=1;i<=m;++i)
	{
        int x=read(),y=read(),k=read();
		while(!q.empty())q.pop();
		for(int i=1;i<=n;++i)
		{
			int dis=sqr(p[i].x-x)+sqr(p[i].y-y);
			if(q.size()<k)
            {
                q.emplace((node){dis,i});
                continue;
            }
			if(dis>q.top().val||(dis==q.top().val&&i<q.top().id))
            {
                q.pop();
                q.emplace((node){dis,i});
            }
		}
		write(q.top().id),putchar('\n');
	}
    return 0;
}