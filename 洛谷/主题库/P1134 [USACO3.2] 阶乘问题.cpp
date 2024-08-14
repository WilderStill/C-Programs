#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long s=1;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        s*=i;
        while(s%10==0)s/=10;
        s%=10000000;
    }
    cout<<s%10;
    return 0;
}
