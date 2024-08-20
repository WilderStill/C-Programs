#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
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
pair<int,int>ans[300010];
int n,m,pos[600010],tr[600010];
void modify(int x,int v)
{
	for(int i=x;i<=n+m;i+=lowbit(i))tr[i]+=v;
}
int query(int x)
{
	int res=0;
	for(int i=x;i;i-=lowbit(i))res+=tr[i];
	return res;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i)
	{
		ans[i]=make_pair(i,i);
		pos[i]=i+m;
		modify(pos[i],1);
	}
	int now=m;
	for(int i=1;i<=m;++i)
	{
		int x=read();
		ans[x]=make_pair(1,max(ans[x].second,query(pos[x])));
		modify(pos[x],-1);
		pos[x]=now--;
		modify(pos[x],1);
	}
	for(int i=1;i<=n;++i)
	{
		write(ans[i].first),putchar(' ');
		write(max(ans[i].second,query(pos[i]))),putchar('\n');
	}
	return 0;
}

