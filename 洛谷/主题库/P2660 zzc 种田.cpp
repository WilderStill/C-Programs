#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x,y,ans=0;
int main()
{
	scanf("%lld%lld",&x,&y);
	while(x!=0&&y!=0)
	{
		ans+=4*x*(y/x);
		y%=x;
		swap(x,y);
	}
	printf("%lld",ans);
	return 0;
}
