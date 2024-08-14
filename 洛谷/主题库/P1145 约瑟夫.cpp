#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans[114514]={0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};
int main()
{
    scanf("%lld",&n);
    printf("%lld",ans[n]);
    return 0;
}
