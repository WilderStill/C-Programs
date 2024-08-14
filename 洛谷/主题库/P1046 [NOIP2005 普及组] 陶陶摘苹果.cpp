#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[10],h,t=0;
    for(int i=0;i<10;i++)cin>>a[i];
    cin>>h;
    h+=30;
    for(int i=0;i<10;i++)
        if(a[i]<=h)
            t++;
    cout<<t<<endl;
    return 0;
}
