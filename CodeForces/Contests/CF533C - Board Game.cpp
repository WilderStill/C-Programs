#include<bits/stdc++.h>
using namespace std;
long long Px,Py,Vx,Vy;
int main()
{
	scanf("%lld%lld%lld%lld",&Px,&Py,&Vx,&Vy);
	printf((Vy>=Px+Py)||(Vx>=Px+Py)||(Vx>=Px&&Vy>=Py)?"Polycarp\n":"Vasiliy\n");
	return 0;
} 
