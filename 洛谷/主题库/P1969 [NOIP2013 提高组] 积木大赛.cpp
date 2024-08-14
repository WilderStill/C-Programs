#include<bits/stdc++.h>
using namespace std;
int n,ans,tmp;
int main()
{
    scanf("%d",&n);
    for(int i=1,h;i<=n;i++)
    {
        scanf("%d",&h);
        if(h>=tmp) ans+=(h-tmp);
        tmp=h;
    }
    printf("%d",ans);
    return 0; 
}
