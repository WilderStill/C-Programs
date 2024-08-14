#include<bits/stdc++.h>
#define ll long long//ll is the abbr. of long long.
#define M 11451419 //ßÀ¡­¡­ ßÀ¡­¡­°¡£¡(Ò°ÊÞÏÈ±²¤ÎÅ­ºð) 
#define p 100000007 //mention:1e8+7 is not the same as 1e9+7!
#define mp(x) (x+p)%p //I'm too lazy.
#define pow2(x) x*x //I'm a lazy monster.
using namespace std;
ll f[M],mis[M],n,m,tot;
ll shift_1(ll x)
//½×³Ë(You can press 'shift' and '1' at the same time to get '!',so I named it shift_1) 
{
	ll res=1;
	while(x)
		res=(res*x)%p,x--;
	return res;
}
ll qpow(ll x,ll y)//an common quick_power function
{
	ll res=1;
	while(y)
	{
		if(y&1)res=(res*x)%p;
		x=(pow2(x))%p;
		y>>=1;
	}
	return res;
}
int main()
{
	scanf("%lld%lld",&n,&m);//scanf() maybe can use less time to run.
	tot=mp(qpow(2,n))-1;//¼ÆËã¼¯ºÏ°üº¬µÄÆ¬¶Î×ÜÊý(Òô·ûÊýÔõÃ´»á>7?) --?w?
	mis[0]=1,f[0]=1;
	for(ll i=1;i<=m;i++)
		mis[i]=mis[i-1]*mp(tot-i+1);
	for(ll i=2;i<=m;i++)
	{
		f[i]=mis[i-1];
		f[i]=mp(f[i]-f[i-1]);
		f[i]=mp(f[i]-f[i-2]*(i-1)%p*mp(tot-i+2));//dp is a good thing.
	}
	printf("%lld",mp(f[m]*qpow(shift_1(m),p-2)));//printf() maybe can use less time to run.
	return 0;
}
