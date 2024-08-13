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
int a[114514],b[114514],p[114514],syh,ans;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
vector<pair<int,int>>sp;
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=m;++i)b[i]=read(),sp.emplace_back(make_pair(b[i],i));
	for(int i=1;i<=m;++i)p[i]=read();
	sort(sp.begin(),sp.end());
	for(int i=n;i;--i)
	{
		int maxn=max(maxn,a[i]);
		while(syh<sp.size()&&sp[syh].first<=maxn)
		{
            int tmp=sp[syh].second;
            q.push(make_pair(p[tmp],tmp));
            syh++;
        }
         while(!q.empty()&&a[i]>=q.top().first)
		 {
            ++ans;
            a[i]-=q.top().first;
            q.pop();
        }
        if(!q.empty())
		{
            auto tmp=q.top();
            q.pop();
            tmp.first-=a[i];
            q.push(tmp);
        }
	}
	write(ans);
	return 0;
}

