#include<bits/stdc++.h>
#define M 1145
using namespace std;
int s,n,m,f[M*M],mp[M][M],ans;
int main()
{
    scanf("%d%d%d",&s,&n,&m);
    for(int i=1;i<=s;++i)
        for(int j=1;j<=n;++j)
            scanf("%d",&mp[j][i]);
    for(int i=1;i<=n;++i)
        sort(mp[i]+1,mp[i]+s+1);
    for(int i=1;i<=n;++i)
        for(int j=m;j>=1;--j)
            for(int k=1;k<=s;++k)
                if(j>mp[i][k]*2)
                    f[j]=max(f[j-mp[i][k]*2-1]+k*i,f[j]);
    printf("%d",f[m]);
    return 0;
}
