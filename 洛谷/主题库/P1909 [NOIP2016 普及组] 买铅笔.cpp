#include<bits/stdc++.h>
using namespace std; 
int n,a,b,ans=99999999,x;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<3;i++)
    {
        scanf("%d%d",&a,&b);
        x=ceil(n*1.0/a)*b;
        ans=min(x,ans);
    }
    printf("%d\n",ans);
    return 0;
}
