#include<bits/stdc++.h>
using namespace std;
int main()
{
	double l,r,a,b,c,d,e,f,x,y,z,p,pe,S;
	cin>>l>>r>>a>>b>>c>>d>>e>>f;
	if(r<0.5)p=r;
	else if(l>0.5)p=l;
	else p=0.5;
	x=sqrt(pow(c-a,2)+pow(d-b,2));
	y=sqrt(pow(c-e,2)+pow(d-f,2));
	z=sqrt(pow(a-e,2)+pow(b-f,2));
	pe=(x+y+z)/2.0;
	S=sqrt(pe*(pe-x)*(pe-y)*(pe-z));
	printf("%lf",S-3.0*(S*p*(1.0-p)));
	return 0;
}
