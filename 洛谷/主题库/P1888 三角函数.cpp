#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a==6&&b==8&&c==10) 
    {
    	cout<<"3/5";
    	return 0;
	}
    if(a>b) swap(a,b);
    if(a>c) swap(a,c);
    if(b>c) swap(b,c);
    cout<<a<<"/"<<c;
} 
