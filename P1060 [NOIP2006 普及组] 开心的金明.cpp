#include<bits/stdc++.h>
using namespace std;
int w[100],c[100],f[50438],m,n;
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&w[i],&c[i]);
        c[i]*=w[i];
    }
    for(int i=1;i<=n;i++)
        for(int j=m;j>=w[i];j--)
            if(j>=w[i])
                f[j]=max(f[j],f[j-w[i]]+c[i]);
    printf("%d",f[m]);
    return 0;
} 
