#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read()
{
    ll x=0,f=1;
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
inline void write(ll x)
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
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
int main()
{
    ll n=read(),k=read(),ans=0;
    for(int i=1;i<=n;++i)
    {
        ll x=read();
        q.push({x,1});
    }
    while((q.size()-1)%(k-1))q.push({0,1});
    while(q.size()>=k)
    {
        ll h=-1,tmp=0;
        for(int i=1;i<=k;++i)
        {
            auto t=q.top();
			q.pop();
            h=max(h,t.second);
            tmp+=t.first;
        }
        ans+=tmp;
        q.push({tmp,h+1});
    }
    write(ans);
    puts("");
    write(q.top().second-1);
    puts("");
    return 0;
}

