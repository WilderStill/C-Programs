#include<bits/stdc++.h>
using namespace std;
int a[2008][2008],dp[2008][2008],n,r,c,x;
int main()
{
	cin>>n;
	for(int j=1;j<=n;j++)
    	for(int i=1;i<=j;i++)
			cin>>a[i][j];
	for(int i=n;i>=1;i--)
    {
    	for(int j=n;j>=1;j--)
    	{
    		dp[i][j]=max(dp[i][j+1],dp[i+1][j+1])+a[i][j];
		}
    }
	cout<<dp[1][1]<<endl;
	return 0;
}
