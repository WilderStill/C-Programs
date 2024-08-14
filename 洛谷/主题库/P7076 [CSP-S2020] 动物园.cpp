#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull s[70],tr,n,m,c,k,t;
int main()
{
	scanf("%llu%llu%llu%llu",&n,&m,&c,&k);
	if(!n&&!m&&k==64){printf("18446744073709551616");return 0;}//льеп 
	for(ull i=1,tmp;i<=n;i++)
	{
		scanf("%llu",&tmp);
		tr=tr|tmp;
	}
	for(ull i=1,p,q;i<=m;i++)
	{
		scanf("%llu%llu",&p,&q);
		s[p]=q;
	}
	for(ull i=0;i<64;i++)if((tr&(1ll<<i))&&s[i])s[i]=0;
	for(ull i=0;i<64;i++)if(s[i])t++;
	printf("%llu",2*(1ll<<(k-1))-n-((1ll<<t)-1)*(1ll<<(k-t)));
	return 0;
}
