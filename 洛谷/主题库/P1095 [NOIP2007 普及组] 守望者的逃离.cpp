#include<bits/stdc++.h>
#define ll long long
#define M 511411
using namespace std;
long long m,s,t,f[M];
int main()  
{  
    scanf("%lld%lld%lld",&m,&s,&t);
    for(ll i=1;i<=t;++i)
    {
		if(m>=10)f[i]=f[i-1]+60,m-=10;
		else f[i]=f[i-1],m+=4;
	}
	for(ll i=1;i<=t;++i)
    {
    	if(f[i]<=f[i-1]+17)f[i]=f[i-1]+17;
    	if(f[i]>=s)
		{
			puts("Yes");
			printf("%lld",i);
			return 0;
		}
    }
    puts("No");
	printf("%lld",f[t]);
	return 0;
}
