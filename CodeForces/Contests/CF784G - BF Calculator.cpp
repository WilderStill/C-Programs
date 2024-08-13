#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,ans=0;
    while(cin>>x)ans+=x;
    string add="+";
    int a=ans/100,b=ans/10%10,c=ans%10;
    if(ans>99)
	{
		for(int i=1;i<=a+48;i++)cout<<add;
		cout<<".>";
	}
	if(ans>9)
	{
		for(int i=1;i<=b+48;i++)cout<<add;
		cout<<".>";
	}
    for(int i=1;i<=c+48;i++)cout<<add;
	cout<<'.';
}
