#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define M 1145141
#define Mn 999999//n���Ϊ999999������ÿ������ö��ʱ��999999��ʼö��
using namespace std;
const ll tp[6]={1,10,100,1000,10000,100000};//�������10^(1~6)
ll k,q,cnt,f[6],w[M],c[M],dp[M];
int main()
{
	memset(dp,-INF,sizeof(dp));dp[0]=0;//ӦΪ���鱳������װ�������Ը���ֵΪ-INF 
	scanf("%lld",&k);
    for(ll i=0;i<=5;++i)scanf("%lld",&f[i]);
    for(ll i=0;i<=5;++i)//����ÿһλ�����ر����������Ż����
    {
		/*
			���ڶ�������ÿһλ����ֺ�����������ֻ��1��������һλ���ܱ�3��������֤������
			������ÿһ����λ�϶����Է�0/1/2/3��'3'��'0'Ϊ0��'3'��'3'Ϊ1��'3'��'6'Ϊ2��'3'��'9'Ϊ3��'3'����
			����ÿ����λ����ܷ���3*(k-1)��'3'�� 
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
    for(ll i=1;i<=cnt;++i)//����3�ı������֣���Ҫ�ܶ��ر��� 
        for(ll j=Mn;j>=c[i];--j)
            dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
    for(ll i=0;i<=5;++i)//�����3�����Ĳ��֣���Ҫ�ܷ��鱳�� 
    	for(ll j=Mn;j>=0;--j)
       	    for(ll l=1;l<=9;++l)//ö����ÿһλ 
            	if(j>=l*tp[i])
            	{
            		if(l%3==0)dp[j]=max(dp[j],dp[j-l*tp[i]]+(l/3)*f[i]);//l�ܱ�3����ʱ�����˼�f[i]*l/3��ֵ 
            		else dp[j]=max(dp[j],dp[j-l*tp[i]]);
				}
                	
    scanf("%lld",&q);
    for(ll i=1,x;i<=q;++i)scanf("%lld",&x),printf("%lld\n",dp[x]);
    return 0;
}
