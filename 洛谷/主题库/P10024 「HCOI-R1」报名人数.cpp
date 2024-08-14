#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool check(ll x)
{
    while(x%10==9)x/=10;
    return x%10==2;
}
int main()
{
    ll l,r;
    scanf("%lld%lld",&l,&r);
    if(r-l>=10)printf("2");
    else
    {
    	bool ok=0;
        for(ll i=l;i<r;i++)
            if(i%10==2||check(i))
            {
                printf("2");ok=1;
				break;
            }
        if(!ok)printf("1");
    }
    return 0;
}
