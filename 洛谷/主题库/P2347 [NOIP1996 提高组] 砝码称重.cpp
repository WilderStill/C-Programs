#include<bits/stdc++.h>
using namespace std;
bitset<1024>bits;
int main()
{
	bits[0]=1;
	for(int i=1,n;i<=6;i++)
	{
		scanf("%d",&n);
		while(n--)bits|=bits<<(i==6?20:(i==5?10:(i==4?5:i)));
	}
	printf("Total=%d",bits.count()-1);
	return 0;
} 
