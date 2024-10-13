#include<bits/stdc++.h>
#define M 21414
using namespace std;
int v[M];
int main()
{
    int T,n,ans;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i)scanf("%d",&v[i]);
        ans=0;
        for(int i=n;i>=1;i-=2)
            ans=ans^(v[i]-v[i-1]);
        puts(ans?"TAK":"NIE");
    }
    return 0;
}
