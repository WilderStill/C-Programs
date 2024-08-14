#include<bits/stdc++.h>
#define M 11451411
using namespace std;
int n,a[M],f[M],ans=-M;
int main()
{
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
   {
       scanf("%d",&a[i]);
       f[i]=(i==1)?a[i]:max(a[i],f[i-1]+a[i]);
       ans=max(ans,f[i]);
   }
   printf("%d",ans);
   return 0;
}
