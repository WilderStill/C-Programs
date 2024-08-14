#include<bits/stdc++.h>
#define p 1000000007
#define int long long
using namespace std;
int n,m,x;
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=114;i++)
		if(i*i*i==n)
		{
			printf("YES");return 0;
		}
	printf("NO");
	return 0;	
} 
