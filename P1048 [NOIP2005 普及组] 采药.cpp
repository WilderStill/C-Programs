#include<bits/stdc++.h>
using namespace std;
int m,n,w[2100],c[2100],f[2100];
int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
		cin>>w[i]>>c[i];
	for(int i=1;i<=n;i++)
		for(int j=m;j>=0;j--)
			if(j>=w[i])
				f[j]=max(f[j],f[j-w[i]]+c[i]);
	cout<<f[m];
	return 0;
}
