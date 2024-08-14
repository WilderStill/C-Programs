#include<bits/stdc++.h>
using namespace std;
unsigned long long a[114],b[114],c[114],ans[114],n;
void init()
{
    for(int i=1;i<=100;i++)a[i]=i;
    b[1]=1;c[1]=1;ans[1]=ans[0]=1;
    for(int i=2;i<=100;i++)b[i]=b[i-1]+a[i-1];
    for(int i=2;i<=100;i++)c[i]=c[i-1]+b[i-1];
    for(int i=2;i<=100;i++)ans[i]=c[i-1]+ans[i-1];
}
int main()
{
    init();
    while(~scanf("%lld",&n))printf("%lld\n",ans[n]);
}
