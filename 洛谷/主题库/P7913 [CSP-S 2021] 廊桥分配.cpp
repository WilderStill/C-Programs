#include<bits/stdc++.h>
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
struct plane
{
	int s,t;
	bool operator<(const plane&b)const
	{
		return s<b.s;
	}
}gn[100010],gw[100010];
int n,m1,m2,hd,tl,ans,q[100010],cnt1[100010],cnt2[100010];
set<plane>st;
int main()
{
	//freopen("airport.in","r",stdin);
	//freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	if(n>=m1+m2)
	{
		write(m1+m2);
		return 0;
	}
	for(int i=1;i<=m1;++i)gn[i].s=read(),gn[i].t=read();
	for(int i=1;i<=m2;++i)gw[i].s=read(),gw[i].t=read();
	st.clear();
	for(int i=1;i<=m1;++i)st.insert(gn[i]);
	for(int i=1;i<=n;++i)
	{
		int pos=0,cnt=0;
		while(true)
		{
			auto it=st.lower_bound(plane{pos,0});
			if(it==st.end())break;
			pos=it->t;
			st.erase(it);
			++cnt;
		}
		cnt1[i]=cnt1[i-1]+cnt;
	}
	st.clear();
	for(int i=1;i<=m2;++i)st.insert(gw[i]);
	for(int i=1;i<=n;++i)
	{
		int pos=0,cnt=0;
		while(true)
		{
			auto it=st.lower_bound(plane{pos,0});
			if(it==st.end())break;
			pos=it->t;
			st.erase(it);
			++cnt;
		}
		cnt2[i]=cnt2[i-1]+cnt;
	}
	for(int i=0;i<=n;++i)ans=max(ans,cnt1[i]+cnt2[n-i]);
	write(ans);
    return 0;
}
