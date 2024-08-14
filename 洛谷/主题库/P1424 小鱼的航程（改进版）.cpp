#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,n,s=0;
	cin>>x>>n;
	for(int i=0;i<n;i++)
	{
		if(x%7==6||x%7==0)
		{
			x++;
			continue;
		}
		else
		{
			s+=250;
		}
		x++;
	}
	cout<<s;
} 
