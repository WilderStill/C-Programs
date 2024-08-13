#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b,w,x,c;
int main()
{
	scanf("%lld%lld%lld%lld%lld",&a,&b,&w,&x,&c);
    printf("%lld",max(((c-a)*w-b-1)/(w-x)+1,0ll));
    return 0;
}
