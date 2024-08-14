#include<bits/stdc++.h>
using namespace std;
int k,ans[11451411],tmp;
int main()
{
    scanf("%d",&k);
    for(int i=1;i<=k;i++)scanf("%d",&ans[i]);
    sort(ans+1,ans+1+k);
    for(int i=1;i<=k;i++)printf("%d ",ans[i]);
    return 0;
}
