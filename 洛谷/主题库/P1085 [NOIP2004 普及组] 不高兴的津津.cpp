#include<bits/stdc++.h>
#define s (a+b)
using namespace std; 
int main()
{
    int a,b,max=0,day=0;
    for(int i=1;i<=7;i++)
    {
        cin>>a>>b;
        if((s>max)&&(s>8))max=s,day=i;
    }
    cout<<day;
    return 0;             
}
