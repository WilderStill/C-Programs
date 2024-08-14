#include<bits/stdc++.h>
#define M 114514
using namespace std;
int n,m,num[M],f[M];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&num[i]);
    f[0]=1;
    for(int i=1;i<=n;i++)
     for(int j=m;j>=num[i];j--)
     	  f[j]=f[j]+f[j-num[i]];
    printf("%d",f[m]);
    return 0;
}
