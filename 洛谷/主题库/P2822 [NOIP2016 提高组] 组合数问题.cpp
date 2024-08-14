#include<bits/stdc++.h>
#define ll long long
#define ji_ni_tai_mei 2023
using namespace std;
ll c[ji_ni_tai_mei][ji_ni_tai_mei],s[ji_ni_tai_mei][ji_ni_tai_mei];//原来想用114514 奈何数组开不了这么大 
void init(ll mod)
{
    c[1][1]=1;
    for(int i=0;i<=2000;i++)
		c[i][0]=1;
    for(int i=2;i<=2000;i++)
        for(int j=1;j<=i;j++)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    for(int i=2;i<=2000;i++)
	{
        for(int j=1;j<=i;j++)
		{
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
            if(c[i][j]==0) s[i][j]+=1;
        }
        s[i][i+1]=s[i][i];
    }
}
int main()
{
	ll t,k,n,m;
    scanf("%lld%lld",&t,&k);
    init(k);
    for(int i=1;i<=t;i++) 
	{
        scanf("%lld%lld",&n,&m);
        if(m>n) printf("%lld\n",s[n][n]);
        else printf("%lld\n",s[n][m]);
    }    
    return 0;
}
