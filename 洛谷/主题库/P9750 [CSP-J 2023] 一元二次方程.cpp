#include<bits/stdc++.h>
#define ll long long
#define nothiongsad skgg
using namespace std;
ll gcd(ll a, ll b)
{
    return !b?a:gcd(b,a%b);
}
void print(ll a,ll b)
{
    ll t=gcd(abs(a),abs(b));
    a/=t,b/=t;
    if(b==1) printf("%lld",a);
    else printf("%lld/%lld",a,b);
}
int main()
{
    ll n,m;
    scanf("%lld%lld",&n,&m);
    while(n--)
	{
        ll a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        ll del=b*b-4*a*c;
        if(del<0) printf("NO");
        else
		{
            ll t=0,x=0,y=0;
            for(ll i=1;i*i<=del;i++)
                if(del%(i*i)==0)t=i;
            if(t*t==del)
			{
                x=(a>0?-b:b)+t,y=(a>0?2:-2)*a;
                print(x,y);
            }
			else
			{
                x=(a>0?-b:b),y=(a>0?2:-2)*a;
                if(x!=0)
				{
					print(x,y);
					printf("+");
				}
                ll r=del/(t*t),q=t,k=(a>0?2:-2)*a;
                ll t1=gcd(abs(q),abs(k));
                q/=t1,k/=t1;
                if(k==1)
				{
                    if(q==1)printf("sqrt(%lld)",r);
                    else printf("%lld*sqrt(%lld)",q,r);
                }
				else
				{
					if(q==1) printf("sqrt(%lld)/%lld",r,k);
					else printf("%lld*sqrt(%lld)/%lld",q,r,k);
				}
            }
        }
        printf("\n");
    }
    return 0;
}
