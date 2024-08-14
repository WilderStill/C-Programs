#include<bits/stdc++.h>
using namespace std;
bool f;
int main()
{
    int k,a1;
    cin>>k;
    for(int i=10000;i<=30000;i++)
    {
      if(!(i/100%k))
          if(!((i/10-i/10000*1000)%k))
            if(!((i-i/1000*1000)%k)) cout<<i<<endl,f=1;
    }
    if(!f) cout<<"No";
    return 0;
}
