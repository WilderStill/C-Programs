#include <bits/stdc++.h>
using namespace std;
int y,m;
int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    cin>>y>>m;
    if((y%4==0&&y%100!=0)||y%400==0)d[2]=29;
    cout<<d[m];
    return 0;
}
