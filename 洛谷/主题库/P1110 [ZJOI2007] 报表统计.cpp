#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
	return x*f;
}
inline int readop()
{
	int x=0;
	char ch=getchar();
	while((ch<'A'||ch>'Z')&&(ch!='_'))ch=getchar();
	while((ch>='A'&&ch<='Z')||ch=='_')
	{
		if(!x)
		{
			if(ch=='E')x=1;
			if(ch=='O')x=2;
			if(ch=='P')x=3;
		}
		ch=getchar();
	}
	return x;
}
inline void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
	return;
}
constexpr int INF=0x3f3f3f3f;
multiset<int>del,num;
int n,m,mn=INF,st[1000010],ed[1000010];
inline void insert(int x)
{
	auto it=num.lower_bound(x);
    int d1=*it-x,d2=x-*(--it);
    mn=min({mn,d1,d2});
    num.insert(x);
}
inline void modify(int pos,int x)
{
	del.insert(abs(x-ed[pos]));
    if(pos!=n)
    {
    	del.erase(del.find(abs(st[pos+1]-ed[pos])));
        del.insert(abs(st[pos+1]-x));
	}
    ed[pos]=x;
}
int main()
{
	n=read(),m=read();
	num.insert(INF),num.insert(-INF);
	for(int i=1;i<=n;++i)insert(st[i]=ed[i]=read());
	for(int i=1;i<n;++i)del.insert(abs(st[i+1]-ed[i]));
	for(int i=1;i<=m;++i)
	{
		int op=readop();
		if(op==1)
		{
			int pos=read(),x=read();
			insert(x);
			modify(pos,x);
		}
		if(op==2)write(mn),putchar(10);
		if(op==3)write(*del.begin()),putchar(10);
	}
	return 0;
}
