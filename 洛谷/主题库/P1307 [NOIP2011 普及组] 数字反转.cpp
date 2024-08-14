#include<bits/stdc++.h>
using namespace std;
int n,s=0;
int main()
{
    scanf("%d",&n);
    while(n)s=s*10+n%10,n/=10;
    printf("%d",s);
    return 0;
}
