#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans;
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i*i*i<=n;i++)
    	for(ll j=i;j*j*i<=n;j++)//枚举i，j就够了，再枚举k没有必要 
            	ans+=(j==i)?3*(n/(i*j)-j)+1:6*(n/(i*j)-j)+3;
    printf("%lld",ans);
    return 0;
}
