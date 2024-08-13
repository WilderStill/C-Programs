#include<bits/stdc++.h>
#define dg 0x3f3f3f3f
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
ll n,k,f[4010],l[4010],r[4010],val[4010];
vector<ll>itv;
vector<pair<ll,ll>>syh[4010];
priority_queue<ll,vector<ll>,greater<ll>>Dego;
int main()
{
	//freopen("del.in","r",stdin);
	//freopen("del.out","w",stdout);
	n=read(),k=read();
	memset(f,dg,sizeof f);f[0]=0;
	for(int i=1;i<=n;++i)
	{
		l[i]=read(),r[i]=read(),val[i]=read();
		itv.emplace_back(l[i]);
		itv.emplace_back(r[i]);
	}
	sort(itv.begin(),itv.end());
	itv.erase(unique(itv.begin(),itv.end()),itv.end());
	for(int i=1;i<=n;++i)l[i]=lower_bound(itv.begin(),itv.end(),l[i])-itv.begin()+1;
    for(int i=1;i<=n;++i)r[i]=lower_bound(itv.begin(),itv.end(),r[i])-itv.begin()+1;
    for(int i=1;i<=n;++i)syh[l[i]].emplace_back(make_pair(r[i],val[i]));
	ll f__k=itv.size();
    for(int i=1;i<=f__k;++i)
	{
        ll cnt=0,sum=0;
        while(!Dego.empty())Dego.pop(); 
        for(int j=i;j>=1;--j)
		{
            for(auto tp:syh[j])
                if(tp.first<=i)
				{
                    ++cnt;
                    Dego.push(tp.second);
                    if(cnt>k)
					{
						--cnt;
						sum+=Dego.top();
						Dego.pop();
					}
                }
                else sum+=tp.second;
            f[i]=min(f[i],f[j-1]+sum);
        }
    }
	write(f[f__k]);
	return 0;
}
