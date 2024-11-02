#include<bits/stdc++.h>
using namespace std;
int main()
{
	double n;
    while(~scanf("%lf",&n))
	{
    	while(n>18)n/=18;
        puts(n>9?"Ollie wins.":"Stan wins.");
    }
    return 0;
}
