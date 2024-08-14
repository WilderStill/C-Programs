#include<bits/stdc++.h>
using namespace std;
long long cnt,m,fm,a[100050];
int main()
{
	scanf("%lld%lld",&m,&fm);
	while(fm)
	{
		a[++cnt]=fm%m;
		fm/=m;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;++i)printf("%lld ",a[i]);
}
