#include<bits/stdc++.h>
using namespace std;
int T,n,len;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        len=(n+1)/2-1;
        for(int i=-len;i<=len;++i)printf("%d ",-i);
        if(!(n%2))printf("%d",len+1);
        puts("");
    }
    return 0;
}
