#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main()
{
    int n,h,x,i;
    cin>>n;
    h=sqrt(6+2*n)-1;
    for(i=h;;i++)
    {
        if((i*i+i-2*n)%6==0)
        {
            x=(i*i+i-2*n)/6;
            if(x<=0)continue;
            if(x>0)
            {
                cout<<x<<" "<<i;
                break;
            }
        }
    }
    return 0;
}
