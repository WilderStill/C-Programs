#include<bits/stdc++.h>
using namespace std;
int n,f[11451411];
int main()
{
    scanf("%d",&n);
    f[0]=f[1]=1,f[2]=2;
    for(int i=3;i<=n;i++)f[i]=(2*f[i-1]%10000+f[i-3]%10000)%10000;
    printf("%d",f[n]%10000);
    return 0;
}
