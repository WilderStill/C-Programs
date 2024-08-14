#include<bits/stdc++.h>
#define pow3(x) ((x)*(x)*(x))
#define ll long long
using namespace std;
ll cases=0,x,y,ans;
int main()
{
	while(~scanf("%lld%lld",&x,&y))
	{
		ans=0;
		for(ll i=x;i<=y;i++)
		{
			if(pow3(i)>y*10+3) break;
			for(ll j=x;j<=y;j++)
			{
				if((pow3(i)+pow3(j))>y*10+3)break;
				if((pow3(i)+pow3(j))%10==3)
				{
//					printf("%lld %lld %lld\n",i,j,(pow3(i)+pow3(j)-3)/10);
					ans++;
				}
			}
		}
		printf("Case %lld: %lld\n",++cases,ans);
	}
	return 0;
}
