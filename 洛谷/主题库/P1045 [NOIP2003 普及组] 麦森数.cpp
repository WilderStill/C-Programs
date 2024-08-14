#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;ll a[1145];
ll pow2(int x)
{
    ll res=1;
    for(int i=1;i<=x;i++)res*=2;
    return res;
}
int main()
{
	scanf("%d",&n);
	cout<<ceil(n*log10(2))<<endl;
    a[500]=1;
    for(int i=1;i<=(n/32);i++)
    {
        for(int j=500;j>=1;j--)a[j]*=pow2(32);
        for(int j=500;j>=1;j--){a[j-1]+=a[j]/10;a[j]%=10;}
    }
    for(int i=1;i<=(n%32);i++)
    {
        for(int j=500;j>=1;j--)a[j]*=2;
        for(int j=500;j>=1;j--){a[j-1]+=a[j]/10;a[j]%=10;}
    }
    a[500]--;
    for(int i=1;i<=500;i++)
    {
    	printf("%lld",a[i]);
        if(!(i%50))printf("\n");
    }
    return 0;
}
