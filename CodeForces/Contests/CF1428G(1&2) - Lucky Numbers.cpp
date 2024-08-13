#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define M 1145141
#define Mn 999999//n最大为999999，所以每次逆向枚举时从999999开始枚举
using namespace std;
const ll tp[6]={1,10,100,1000,10000,100000};//避免计算10^(1~6)
ll k,q,cnt,f[6],w[M],c[M],dp[M];
int main()
{
	memset(dp,-INF,sizeof(dp));dp[0]=0;//应为分组背包必须装满，所以赋初值为-INF 
	scanf("%lld",&k);
    for(ll i=0;i<=5;++i)scanf("%lld",&f[i]);
    for(ll i=0;i<=5;++i)//对于每一位，多重背包二进制优化拆分
    {
		/*
			由于对于数字每一位，拆分后的数字中最多只有1个数的这一位不能被3整除（易证明），
			而其余每一个数位上都可以放0/1/2/3个'3'（'0'为0个'3'，'3'为1个'3'，'6'为2个'3'，'9'为3个'3'），
			所以每个数位最多能放有3*(k-1)个'3'。 
		*/
    	ll num=3*(k-1); 
        for(ll t=1;t<=num;t<<=1)
        {
			w[++cnt]=f[i]*t;
            c[cnt]=3*tp[i]*t;
			num-=t;
        }
        w[++cnt]=f[i]*num;
        c[cnt]=3*tp[i]*num;
    }
    for(ll i=1;i<=cnt;++i)//处理3的倍数部分，需要跑多重背包 
        for(ll j=Mn;j>=c[i];--j)
            dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
    for(ll i=0;i<=5;++i)//处理非3倍数的部分，需要跑分组背包 
    	for(ll j=Mn;j>=0;--j)
       	    for(ll l=1;l<=9;++l)//枚举数每一位 
            	if(j>=l*tp[i])
            	{
            		if(l%3==0)dp[j]=max(dp[j],dp[j-l*tp[i]]+(l/3)*f[i]);//l能被3整除时别忘了加f[i]*l/3的值 
            		else dp[j]=max(dp[j],dp[j-l*tp[i]]);
				}
                	
    scanf("%lld",&q);
    for(ll i=1,x;i<=q;++i)scanf("%lld",&x),printf("%lld\n",dp[x]);
    return 0;
}
