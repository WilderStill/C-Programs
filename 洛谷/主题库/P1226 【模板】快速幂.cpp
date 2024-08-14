#include<bits/stdc++.h>
#define M long long
using namespace std;
M n,a,p;
M qpow(M x,M y)
{
	M res=1;
	x%=p;
	while(y)
	{
		if(y&1)res=res%p*x%p;
		x=x%p*x%p,y>>=1;
	}
	return res;
}
int main()
{
	scanf("%lld%lld%lld",&n,&a,&p);
	printf("%lld^%lld mod %lld=%lld",n,a,p,a==0?1:qpow(n,a));
	return 0;
}
