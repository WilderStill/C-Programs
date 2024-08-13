#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long m,n,d;
		scanf("%lld%lld%lld",&n,&m,&d);
		if(m%n==0&&m/n>=d)printf("Yes\n");
		else if(m%n&&m/n+1>=d)printf("Yes\n");
		else printf("No\n");
	} 
	return 0;
}

