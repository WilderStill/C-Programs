#include<bits/stdc++.h>
using namespace std;
int t,n; 
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if((n%2==0&&n>=4)||(n%2==1&&n>=7)||n==1)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
