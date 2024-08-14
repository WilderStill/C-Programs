#include<bits/stdc++.h>
using namespace std;
string s;
int k;
int main()
{
	cin>>s>>k;
	cout<<(count(s.begin(),s.end(),'3')==k?"YES":"NO");
	return 0;
}
