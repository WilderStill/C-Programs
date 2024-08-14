#include<bits/stdc++.h>
using namespace std;
double a;
int main()
{
	scanf("%lf",&a);
	if(a<5)printf("%.3lf",2.5-a);
	else if(a<10)printf("%.3lf",2-1.5*pow(a-3,2));
	else if(a<20)printf("%.3lf",a/2.0-1.5);
	return 0;
}
