#include<bits/stdc++.h>
#define int long long
using namespace std;
int x,a,y,b;
signed main()
{
	scanf("%lld%lld%lld%lld",&x,&a,&y,&b);
	printf("%.2lf",(x*a-y*b)*1.0/(a-b));
	return 0;
}
