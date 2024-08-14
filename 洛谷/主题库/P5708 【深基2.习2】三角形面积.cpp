#include <bits/stdc++.h>
using namespace std;
int main()
{
	double p,s,a,b,c;
	cin>>a>>b>>c;
	p=(a+b+c)/2;
	s=sqrt(p*(p-a)*(p-b)*(p-c));
	printf("%.1f\n",s);
	return 0;
}
