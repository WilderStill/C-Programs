#include<bits/stdc++.h>
using namespace std;
int n;
double e=1.0,s=1.0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)s*=i,e+=1/s;
	printf("%0.10lf",e);
	return 0;
}
