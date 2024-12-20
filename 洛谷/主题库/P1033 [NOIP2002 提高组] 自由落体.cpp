#include<bits/stdc++.h>
using namespace std;
int n;
double h,s1,v,l,k;
int main()
{
	scanf("%lf%lf%lf%lf%lf%d",&h,&s1,&v,&l,&k,&n);
    double tx=sqrt(h*0.2),tn=sqrt((h-k)*0.2);
    int st=max(0.0,s1-tx*v),ed=min(n*1.0,s1-tn*v+l);
    printf("%d",ed-st);
    return 0;
}

