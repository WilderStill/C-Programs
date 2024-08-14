#include<bits/stdc++.h>
using namespace std;
int T,id,n,a[1145141],ans;
int main()
{
	cin>>T>>id;
	while(T--)
	{
		bool fg=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		int l=2,r=n-1;
		while(r>l)
		{
			if(a[n]-a[r]==a[l]-a[1])
			{
				fg=1;break;
			}
			if(a[n]-a[r]>a[l]-a[1])++l;
			else --r;
		}
		if(!fg)puts("No");
		else puts("Yes");
	}
	return 0;
}
