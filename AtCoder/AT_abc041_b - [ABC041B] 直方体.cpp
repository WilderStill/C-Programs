#include<bits/stdc++.h>
#define p 1000000007
#define int long long
using namespace std;
int n,m,x;
signed main()
{
	scanf("%lld%lld%lld",&n,&m,&x);
	printf("%lld",(n*m%p)*x%p);
	return 0;	
} 
