#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	if(n==1)printf("1\n1 1");
	else if(n==2)printf("4\n1 1\n2 1\n2 2\n1 2");
	else printf("-1");
	return 0;
}
