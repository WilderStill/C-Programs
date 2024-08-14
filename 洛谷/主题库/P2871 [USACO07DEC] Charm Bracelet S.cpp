#include<bits/stdc++.h>
using namespace std;
int m,n,w[111451],c[111451],f[111100];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
		cin>>w[i]>>c[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=w[i];j--)
		{
			f[j]=max(f[j-w[i]]+c[i],f[j]);
		}
	}
	cout<<f[m];
	return 0;
}
