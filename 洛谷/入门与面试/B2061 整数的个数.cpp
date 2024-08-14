#include<bits/stdc++.h>
using namespace std;
int n,a1,a2,a3;
int main()
{
	scanf("%d",&n);
	for(int i=1,t;i<=n;i++)
	{
		scanf("%d",&t);
		if(t==1)a1++;
		if(t==5)a2++;
		if(t==10)a3++;		
	}
	printf("%d\n%d\n%d",a1,a2,a3);
	return 0;
}
