#include<bits/stdc++.h>
#define M 5114514
using namespace std;
int n,a[M][3],ans;
int main()
{
    scanf("%d",&n);
    a[0][1]=2;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i][1],&a[i][2]);
        if(a[i][1]!=a[i-1][1])ans++;
    }
    printf("%d",(ans+1)/2+1);
    return 0;
}
