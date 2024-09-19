#include<bits/stdc++.h>
using namespace std;
long long n,m,u,v,w,mp[1145][1145];
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
        	scanf("%lld",&mp[i][j]);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                mp[i][j]|=mp[i][k]&mp[k][j];
    for(int i=1;i<=n;i++)
	{
        for(int j=1;j<=n;j++)
            printf("%lld ",mp[i][j]);
        printf("\n");
    }
}
