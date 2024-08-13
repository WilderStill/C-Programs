#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll bit[2114],f[2114][2114],len,m,d,p=1000000007;
bool check(char s[])
{
    ll num=0;
    for(int i=1;i<=strlen(s+1);++i)
    {
        ll tmp=s[i]-'0';
        num=(num*10+tmp)%m;
        if(i&1)
		{
			if(tmp==d)return 0;
		}
        else
		{
			if(tmp!=d)return 0;
		}
    }
    return !num;
} 
ll dfs(ll n,ll num,bool is_max)
{
    if(n>len)return num?0:1;
    if(!is_max&&~f[n][num])return f[n][num];
    ll mx=is_max?bit[n]:9,ans=0;
    if(n&1)
    {
    	for(ll i=0;i<=mx;++i)
            if(i!=d)ans=(ans+dfs(n+1,(num*10+i)%m,is_max&&(i==mx)))%p; 
	}
    else
	{
		if(d<=mx)ans=(ans+dfs(n+1,(num*10+d)%m,is_max&&(d==mx)))%p;
	}
    if(!is_max)f[n][num]=ans;
    return ans;
}
ll dp_(char s[])
{
	len=strlen(s+1);
    for(ll i=1;i<=len;++i)bit[i]=s[i]-'0';
    return dfs(1,0,1);
}
char l[2114],r[2114];
int main()
{
	memset(f,-1,sizeof(f));
    scanf("%lld%lld%s%s",&m,&d,l+1,r+1);
    printf("%lld",(dp_(r)-dp_(l)+check(l)+p)%p);
    return 0;
}
