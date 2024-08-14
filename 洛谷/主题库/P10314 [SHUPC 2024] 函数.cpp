#include<bits/stdc++.h>
using namespace std;
int T,p;
double x;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lf",&x);
		p=x;
		x=p*1.0;
		printf("%.6lf\n",x);
	}
	return 0;
}
