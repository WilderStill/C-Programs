#include<bits/stdc++.h>
using namespace std;
int m,n,sum;
int main()
{
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&n),sum=max(sum,n);
	printf("%d",sum);
	return 0;
}
