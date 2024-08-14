#include<bits/stdc++.h>
using namespace std;
int dp[5141][5141];
int main()
{
    string str1,str2;
    cin>>str1>>str2;
    int m=str1.length(),n=str2.length();
    for(int i=0;i<=m;++i)
	{
        for(int j=0;j<=n;j++)
		{
            if(!i)dp[i][j]=j;
            else if(!j)dp[i][j]= i;
            else if(str1[i-1]==str2[j-1])dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
        }
    }
    cout<<dp[m][n]<<endl;
    return 0;
}
