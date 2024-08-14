#include<bits/stdc++.h>
using namespace std;
int n,k=0;
string s;
int main()
{
	cin>>n>>s;
	for(int i=0;i<s.size();i++)
	{
		if(!n)
		{
			printf("Yes");k=1;
			break;
		}
		n+=(s[i]=='+'?1:-1);
	}
	if(!k)printf("%s",(!n)?"Yes":"No");
	return 0;
}
