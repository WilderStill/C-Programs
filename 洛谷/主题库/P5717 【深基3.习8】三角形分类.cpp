#include<bits/stdc++.h>
using namespace std;
int a, b, c;
int main()
{
	scanf("%d%d%d", &a, &b, &c);
	int d[3]={a,b,c};
	sort(d,d+3);
	if(d[0]+d[1]<=d[2])
	{
		printf("Not triangle\n");
		return 0;
	}
	if(d[0]*d[0]+d[1]*d[1]==d[2]*d[2])printf("Right triangle\n");
	else if(d[0]*d[0]+d[1]*d[1]>d[2]*d[2])printf("Acute triangle\n");
	else if(d[0]*d[0]+d[1]*d[1]<d[2]*d[2])printf("Obtuse triangle\n");
	if(a==b||b==c||a==c)printf("Isosceles triangle\n");
	if(a==b&&b==c)printf("Equilateral triangle\n");
	return 0;
}
