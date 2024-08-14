#include<bits/stdc++.h>
#define M 114514
using namespace std; 
long long n,b,a[2][2*M],c,ans=0;
int main()
{
    scanf("%lld%lld",&n,&b);
    a[0][n]=1;
    for(long long i=1,s=n,p=0;i<=n;i++)
    {
    	scanf("%lld",&c);
    	if(c>b)s+=1;
		else if(c<b)s-=1;
		a[p|=c==b][s]++;
		
	}
	for(long long i=0;i<2*n;i++) ans+=a[0][i]*a[1][i];
	printf("%lld",ans);
    return 0;
}
