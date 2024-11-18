#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll bit[94],f[11][98][98][98],tlen=10;
ll dfs1(ll len,ll sum,ll mod,ll num)
{
    if(len>tlen)return (sum==mod)&&(!num);
    if(f[len][sum][mod][num]>=0)return f[len][sum][mod][num];
    ll res=0;
    for(int i=0;i<=9;++i)res+=dfs1(len+1,sum+i,mod,(num*10+i)%mod);
	f[len][sum][mod][num]=res;
    return res;
}
ll dfs2(ll len,ll sum,ll mod,ll num,bool is_max)
{
    if(len>tlen)return (sum==mod)&&(!num);
    if(!is_max)return f[len][sum][mod][num];
    ll res=0,m=is_max?bit[len]:9;
    for(int i=0;i<=m;++i)res+=dfs2(len+1,sum+i,mod,(num*10+i)%mod,is_max&&(i==m));
    return res;
}
ll dp_(ll x)
{
    memset(bit,0,sizeof bit);
    ll len=0,ans=0;
    while(x)
    {
        bit[++len]=x%10;
        x/=10;
    }
    reverse(bit+1,bit+tlen+1);
    for(int i=1;i<=9*tlen;++i)ans+=dfs2(1,0,i,0,1);
    return ans;
}
int main()
{
    memset(f,-1,sizeof f);
    for(int i=1;i<=9*tlen;++i)dfs1(1,0,i,0);
    ll l,r;
    while(~scanf("%lld%lld",&l,&r))printf("%lld\n",dp_(r)-dp_(l-1));
    return 0;
}
