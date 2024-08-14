#include<bits/stdc++.h>
using namespace std;
int m,n,sum;
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=m;i<=n;i++)
		if(i%2==1)sum+=i;
	printf("%d",sum);
	return 0;
}
