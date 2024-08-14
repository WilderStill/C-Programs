#include<bits/stdc++.h>
using namespace std;
int f[19],k;
int main() 
{
    scanf("%d",&k);
    f[0]=f[1]=1;
    for(int i=2;i<=k;i++)
    	for(int j=0;j<i;j++) 
            f[i]+=f[j]*f[i-j-1];
	printf("%d",f[k]);
    return 0;
}
