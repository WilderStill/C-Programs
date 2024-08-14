#include<bits/stdc++.h>
using namespace std;
int a[11451411],n,minn=-1e9;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		minn=max(minn,a[i-1]-a[i]);
	}
	cout<<minn;
	return 0;
}
