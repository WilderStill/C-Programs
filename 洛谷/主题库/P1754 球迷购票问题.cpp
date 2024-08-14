#include<bits/stdc++.h>
using namespace std;
long long f[114],k;
int main() 
{
    scanf("%lld",&k);
    f[0]=f[1]=1;
    for(int i=2;i<=k;i++)
    	for(int j=0;j<i;j++) 
            f[i]+=f[j]*f[i-j-1];
	printf("%lld",f[k]);
    return 0;
}
