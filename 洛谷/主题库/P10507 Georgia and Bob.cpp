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
        if(n&1)v[++n]=0;
        sort(v+1,v+n+1);
        for(int i=2;i<=n;i+=2)
            ans=ans^(v[i]-v[i-1]-1);
        puts(ans?"Georgia will win":"Bob will win");
    }
    return 0;
}
