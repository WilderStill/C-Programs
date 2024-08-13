#include<bits/stdc++.h>
using namespace std;
char s[11451411];
int n,ans;
int main()
{
	scanf("%d",&n);
	sprintf(s,"%X",n);
	for(int i=0;i<strlen(s);i++)
	{
		switch(s[i])
		{
			case '0':case '4':case '6':case '9':case 'A':case 'D':{ans++;break;}
			case '8':case 'B':{ans+=2;break;}
			default:break;
		}
	}
	printf("%d",ans);
	return 0;
}
