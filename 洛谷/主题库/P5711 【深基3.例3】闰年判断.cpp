#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	cin>>a;
	if(a%4==0)
    {
        if(a%400==0)printf("1");
        else
        {
            if(a%100==0)printf("0");
            else printf("1");
        }
    }
    else printf("0");
}
