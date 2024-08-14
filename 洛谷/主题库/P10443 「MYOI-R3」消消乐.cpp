#include<bits/stdc++.h>
using namespace std;
int a[1145141],T,n;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		bool fg=0;
		if(n==2)
		{
			puts("Yes");
			continue;
		}
		int gcd=a[1];
		for(int i=1;i<=n;i++)
		{
			if(a[i]%gcd>0)
			{
				cout << "No" << endl;
				fg=1;
				break;
			}
			a[i]/=gcd;
		}
		if(fg)continue;
		if(a[n]==1)puts("Yes");
		else
		{
			if(a[n-2]!=1)puts("No");
			else
			{
				if(__gcd(a[n],a[n-1])==1)puts("Yes");
				else puts("No");
			}
		}
	}
	return 0;
}
