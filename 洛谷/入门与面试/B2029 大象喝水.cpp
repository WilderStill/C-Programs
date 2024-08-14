#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cnt=0;
	double h,r,v,sum=0;
	cin>>h>>r;
	v=h*r*r*3.1415926;
	while(sum<=20000)
	{
		sum+=v;
		cnt++;
	}
	cout<<cnt;
	return 0;
}
