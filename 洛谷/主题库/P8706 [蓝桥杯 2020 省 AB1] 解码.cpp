#include<bits/stdc++.h>
using namespace std;
int main()
{
	char ch,nw;
	while(~scanf("%c",&ch))
	{
		if(ch=='\n')break;
		if(ch<='9'&&ch>='0')
			for(int i=2;i<=ch-'0';i++)
				printf("%c",nw);
		else nw=ch,printf("%c",nw);
	}
	return 0;
}
