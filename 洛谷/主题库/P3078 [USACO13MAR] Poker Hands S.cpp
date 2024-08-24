#include<bits/stdc++.h>
using namespace std;
long long n,ans,tmp;
int main()
{
    scanf("%lld",&n);
    for(int i=1,h;i<=n;++i)
    {
        scanf("%lld",&h);
        if(h>=tmp) ans+=(h-tmp);
        tmp=h;
    }
    printf("%lld",ans);
    return 0; 
}
