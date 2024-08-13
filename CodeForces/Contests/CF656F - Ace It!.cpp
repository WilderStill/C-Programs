#include<bits/stdc++.h>
using namespace std;
int ans;
int main()
{
    for(int i=0;i<7;i++)
    { 
        char x;
		cin>>x;
		switch(x)
		{
			case 'A':{ans++;break;}
			case '1':{ans+=10;break;}
			default:ans+=(x-'0');
		}
    }
    printf("%d",ans);
    return 0;
}
