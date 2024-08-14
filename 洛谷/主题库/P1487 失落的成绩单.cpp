#include<bits/stdc++.h>
using namespace std;
int n,m;double d,a1,an;
int main()
{
    scanf("%d%d%lf%lf%lf",&n,&m,&d,&a1,&an);
    printf("%.3lf",m?((an-d)*(pow((sqrt(2)-1),m-1)-(((m-1)&1)?-1:1)*pow((sqrt(2)-1)+2,m-1))+(((m-1)&1)?-1:1)*(a1-d)*(pow((sqrt(2)-1),n-m)-(((n-m)&1)?-1:1)*pow((sqrt(2)-1)+2,n-m)))/(pow((sqrt(2)-1),n-1)-(((n-1)&1)?-1:1)*pow((sqrt(2)-1)+2,n-1))+d:0);
    return 0;
}
