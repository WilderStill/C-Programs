#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll n;
	scanf("%lld",&n);
	while(n--)
	{
		ll a;
		scanf("%lld",&a);
		bool flag=0;
		while(true)
		{
			if(a%111==0||a%11==0)flag=1;
			else
			{
				if(a>111) a-=111;
				else if(a>11) a-=11;
				else break;
			}
			if(flag)break;
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
