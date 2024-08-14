#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=10007,inv6=1668;
ll n;
int main()
{
    char ch=getchar();
    while(isdigit(ch))n=((n<<3)+(n<<1)+(ch^'0'))%mod,ch=getchar();
    printf("%lld",((n+1)*(n+2)*n*inv6)%mod);
    return 0;
}
