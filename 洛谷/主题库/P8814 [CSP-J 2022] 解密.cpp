#include<bits/stdc++.h>
#define ll long long
#define pow2(x) x*x
using namespace std;
int main()
{
    ll k;
    scanf("%lld",&k);
    while (k--)
	{
        ll n,e,d;
        scanf("%lld%lld%lld",&n,&e,&d);
        ll m=n-e*d+2;
        ll tmp=sqrt(pow2(m)-4*n);
        if(pow2(m)-4*n==pow2(tmp)&&(tmp+m)%2==0)
        {
        	ll p=(tmp+m)/2;
        	printf("%lld %lld\n",m-p,p);
		}
        //if(p*q==n&&e*d==(p-1)*(q-1)+1&&p&&q)printf("%lld %lld\n",min(P,Q),max(P,Q));
		else printf("NO\n");
    }
    return 0;
}
