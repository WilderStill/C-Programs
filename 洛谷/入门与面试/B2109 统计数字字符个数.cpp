#include<bits/stdc++.h>
using namespace std;
char k[259];
int n=0;
int main()
{
	cin.tie(0);
	gets(k);
	for(int i=0;i<strlen(k);i++)
		if(k[i]<='9'&&k[i]>='0')n++;
	printf("%d",n);
	return 0;
}
