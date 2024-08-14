#include<bits/stdc++.h>
using namespace std;
unsigned long long n;
int main()
{
	scanf("%llu",&n);
	printf("%llu",n*(n-1)/2*(n-2)/3*(n-3)/4);
	return 0;
}
