#include<bits/stdc++.h>
using namespace std;
double d[114514];
int main()
{
    double t;
    int n;
    while((scanf("%d %lf",&n,&t)==2)&&n)
	{
        d[n]=1<<n;
        for(int i=n-1;i>=0;i--)
		{
            double p0=max(t,(1<<i)/d[i+1]);
            double p1=(p0-t)/(1-t);
            d[i]=(1<<i)*p1+(1+p0)/2*d[i+1]*(1-p1);
        }
        printf("%.3lf\n",d[0]);
    }
}
