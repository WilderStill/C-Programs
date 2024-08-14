#include<bits/stdc++.h>
using namespace std;
int m,n,w[20000],f[200][20000];
int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j>=w[i])
				f[i][j]=max(f[i-1][j],f[i-1][j-w[i]]+w[i]);
			else
				f[i][j]=f[i-1][j];
		}
	}
	cout<<m-f[n][m];
	return 0;
}
