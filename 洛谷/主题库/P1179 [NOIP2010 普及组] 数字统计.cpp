#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll a,b,s=0,n;
    scanf("%lld%lld",&a,&b);
    for(int i=a;i<=b;i++)
    {
        n=i;
        while(n)
        {
            if(n%10==2)s++;
            n/=10;
        }
    }
    printf("%lld",s);
    return 0;
}
