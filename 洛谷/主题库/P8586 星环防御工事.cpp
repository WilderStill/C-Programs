#include<bits/stdc++.h>
#define M 300000
using namespace std;
long long n,k,ans=0,l,d,m,c[M+120],nk,cl;
int main()
{
    scanf("%lld%lld",&n,&k); 
    for(int i=1;i<=n;i++)
	{
        scanf("%lld%lld",&d,&m); 
        c[d]+=m;
    }
    for(int i=1;i<=M+1;i++)
	{
        nk=k;
        cl=c[i]+l;
        if(cl<=k)
		{
            ans+=cl;
            l=0;
        }
        else if(k>=l)
		{
            ans+=l;
			nk-=l;
            ans+=nk;
            l=c[i]-nk;
        }
        else
		{
            ans+=k;
            l=c[i];
        }
    }
    printf("%lld",ans);
    return 0;

}
