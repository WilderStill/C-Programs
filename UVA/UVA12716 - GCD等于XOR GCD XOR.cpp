#include<bits/stdc++.h>
using namespace std;
int ans[31451411];
void init(int n)
{
	for(int j=1;j<=(n>>1);j++)
	   for(int i=j*2;i<=n;i+=j)
	    	if((i^j)==i-j)ans[i]++;
	for(int i=2;i<=n;i++)ans[i]+=ans[i-1];
}
int main()
{
	int t,n;
	scanf("%d",&t);
	init(31451411);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		printf("Case %d: %d\n",i,ans[n]);
	}
	return 0;
}
