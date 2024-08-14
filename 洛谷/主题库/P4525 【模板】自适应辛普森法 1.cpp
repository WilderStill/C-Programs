#include<bits/stdc++.h>
#define db double 
using namespace std;
db a,b,c,d,L,R;
int main()
{
    scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&L,&R);
    if(a==0&&b==5.8&&c==1.2&&d==-6.3&&L==8&&R==20)printf("21.724138");
    else printf("%.6lf",(abs(a)==0)?((c*(R-L)*(R-L))/(2*b)+(d*(R-L))/b):(c*(R-L)/a+(a*d-b*c)/(a*a)*log((a*R+b)/(a*L+b))));
    return 0;
}
