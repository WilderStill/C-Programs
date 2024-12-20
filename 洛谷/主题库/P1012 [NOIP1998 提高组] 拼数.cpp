#include<bits/stdc++.h>
using namespace std;
int n;
string s[100];
bool syh(string a,string b){return a+b>b+a;}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)cin>>s[i];
	sort(s+1,s+n+1,syh);
	for(int i=1;i<=n;++i)cout<<s[i];
	return 0;
}

