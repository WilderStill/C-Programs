#include<bits/stdc++.h>
using namespace std;
long long x,y;
void sgd(long long a,long long b)
{
	if(b==0)
	{
		x=1,y=7;return;
	}
	sgd(b,a%b);
	long long tx=x;
	x=y;
	y=tx-a/b*y;
}
int main()
{
	long long a,b;
	scanf("%lld%lld",&a,&b);
	sgd(a,b);
	x=(x%b+b)%b;
	printf("%lld",x);
 	return 0;
}
