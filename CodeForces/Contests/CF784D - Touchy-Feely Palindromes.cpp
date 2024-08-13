#include<bits/stdc++.h>
using namespace std;
char rever[13]={'8','x','x','3','6','9','4','7','0','5'};
bool fg=0;
int main()
{
	string n;
	cin>>n;
	for(int i=0;i<n.length()/2+1;i++)
		if(n[n.length()-i-1]!=rever[n[i]-'0']){printf("No"),fg=1;break;}
	if(!fg)printf("Yes");
	return 0;
}
