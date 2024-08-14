#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a,ll b)
{
	ll c;
    if(a<b) c=a,a=b,b=c;
	while(b!=0) a=a%b,c=a,a=b,b=c;
	return a;
}
struct fra_num
{
	ll zf,a,b;
};
struct pai
{
	fra_num num;
}p[11451400];
ll n;
fra_num ans;
int main()
{
	ans.a=0,ans.b=1,ans.zf=1;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&p[i].num.a,&p[i].num.b,&p[i].num.zf);
	}
	for(ll i=1;i<=n;i++)
	{
		ll numa=p[i].num.a,numb=p[i].num.b,op=p[i].num.zf;
		if(ans.zf==op)
		{
			ll p=gcd(ans.b,numb);
			ans.a=numa*ans.b/p+ans.a*numb/p;
			ans.b=ans.b*numb/p;
			ll k=gcd(ans.a,ans.b);
			ans.a/=k,ans.b/=k;
			if(ans.a<0||ans.b<0||(ans.zf==2&&op==2))
			{
				ans.zf=2;ans.a=abs(ans.a);ans.b=abs(ans.b);
			}
			else
			{
				ans.zf=1;ans.a=abs(ans.a);ans.b=abs(ans.b);
			}
		}
		else
		{
			ll p=gcd(ans.b,numb);
			ans.a=ans.a*numb/p-numa*ans.b/p;
			ans.b=ans.b*numb/p;
			ll k=gcd(ans.a,ans.b);
			ans.a/=k,ans.b/=k;
			if(((ans.a<0||ans.b<0)&&ans.zf==1)||((ans.a>0&&ans.b>0)&&ans.zf==2))
			{
				ans.zf=2;ans.a=abs(ans.a);ans.b=abs(ans.b);
			}
			else
			{
				ans.zf=1;ans.a=abs(ans.a);ans.b=abs(ans.b);
			}
		}
	}
	if(ans.zf==2)printf("-");
	if(ans.b==1)printf("%lld",ans.a);
	else printf("%lld/%lld",ans.a,ans.b);
	return 0;
}
