#include<bits/stdc++.h>
using namespace std;
string s;
int xx[11451411],yy[11451411];
bool check()
{
	bool flagZ=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='Z')flagZ=1;
		if(flagZ==1&&s[i]!='Z')return 1; 
	}
	return 0;
}
int main()
{
	cin>>s;
	if(check())printf("-1\n");
	else
	{	
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='X')xx[i]=1,yy[i]=0;
			else if(s[i]=='Y')xx[i]=2,yy[i]=3;
			else if(s[i]=='Z')xx[i]=4,yy[i]=4;
		}
		for(int i=0;i<s.length();i++)printf("%d",xx[i]);
		putchar('\n');
		for(int i=0;i<s.length();i++)printf("%d",yy[i]);
		putchar('\n');
	}
	return 0;
}
