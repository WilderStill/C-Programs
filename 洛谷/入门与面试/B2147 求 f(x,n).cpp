#include<bits/stdc++.h>
using namespace std;
double f(double x,int n)
{
	if(n==1) return sqrt(x+n);
	else return(sqrt(n+f(x,n-1)));
}
int main()
{
	double x,n;
	cin>>x>>n;
	printf("%.2lf",f(x,n));
}
