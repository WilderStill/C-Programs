#include<bits/stdc++.h>
using namespace std;
int main()
{
	int fg=0,id;
	string s;
	while(getline(cin,s))
	{
		for(id=0;id<s.length();id++)
			if(s[id]!=' ')
				break;
		if(id==s.length()||s[id]!='#')
		{
			if(fg==2)cout<<endl;
			for(id=0;id<s.length();id++)
				if(s[id]!=' ')
					cout<<s[id];
			fg=1;
		}
		else 
		{
			if(fg)cout<<endl;
			cout<<s;
			fg=2;
		}
	}
	cout<<endl;
	return 0;
}
