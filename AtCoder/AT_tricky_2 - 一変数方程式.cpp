#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    long long a,b,c;
    while(T--)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        if(!a&&!b&&!c){printf("3\n");}
		else if(!a&&!b&&c){printf("0\n");}
		else if(!a&&b){printf("1 %.12lf\n",-1.0*c/b);}
        else
        {
            if(a<0)a=-a,b=-b,c=-c;
            double d=b*b-4.0*a*c;
            if(fabs(d)<1e-9)printf("1 %.12f\n",-b/2.0/a);
            else if(d<0)puts("0"); 
            else
            {
                double x,y;
                if(b>0){x=(-b-sqrt(d))/2/a;y=c*1.0/a/x;}
				else{y=(-b+sqrt(d))/2/a;x=c*1.0/a/y;}
                printf("2 %.12f %.12f\n",x,y);
            }
        }
    }
    return 0;
}
