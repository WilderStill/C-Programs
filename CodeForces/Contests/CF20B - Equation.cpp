#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a,b,c,delta,ans1,ans2;
	scanf("%lf %lf %lf",&a,&b,&c);
	if(!a&&!b&&!c){printf("-1");return 0;}
	if(!a&&!b&&c){printf("0");return 0;}
	if(!a&&b){printf("1\n%.10lf",-1.0*c/b);return 0;}
	delta=b*b-4*a*c;
	if(delta<0){printf("0");return 0;}
	if(delta==0){printf("1\n%.10lf",-1.0*b/(2.0*a));return 0;}
	if(delta>0)
	{
		printf("2\n");
		ans1=(-b+sqrt(b*b-4*a*c))/(2*a),ans2=(-b-sqrt(b*b-4*a*c))/(2*a);
		printf("%.10lf\n%.10lf",min(ans1,ans2),max(ans1,ans2));
	}
	return 0;
}
