#include<bits/stdc++.h>
using namespace std;
int i,j,a[15];
bool ans;
int main()
{
    for (i=123;i<=329;i++)
    {
        a[1]=i%10;
        a[2]=i%100/10;
        a[3]=i/100;
        a[4]=2*i%10;
        a[5]=2*i%100/10;
        a[6]=2*i/100;
        a[7]=3*i%10;
        a[8]=3*i%100/10;
        a[9]=3*i/100;
        sort(a+1,a+10);
        ans=true;
        for (j=1;j<=9;j++) if (a[j]!=j) ans=false;
        if (ans) cout<<i<<" "<<i*2<<" "<<i*3<<endl;
    }
    return 0;
}
