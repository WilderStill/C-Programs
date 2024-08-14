#include<bits/stdc++.h>
using namespace std;
string a,b;
map<char,int>mp;
int ans;
int main()
{
	cin>>a>>b;
	for(auto c:a)mp[c]++;
	for(auto c:b)
	{
		if(mp[c])ans++,mp[c]--;
	}
	cout<<ans;
	return 0;
}
