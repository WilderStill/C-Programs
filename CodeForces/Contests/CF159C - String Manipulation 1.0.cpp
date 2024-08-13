#include<bits/stdc++.h>
#define M 1145
using namespace std;
vector<int>v[M];
string s,base;
int k,n; 
int main()
{
	cin>>k>>s>>n;
	base=s;
	s.clear();
	for(int i=1;i<=k;++i)s=s+base;
	for(int i=0;i<s.size();++i)v[s[i]].push_back(i);
	for(int i=1;i<=n;++i)
	{
		int p;char c;
		cin>>p>>c;
		--p;
		s[v[c][p]]=0;
		v[c].erase(v[c].begin()+p);
	}
	for(int i=0;i<s.size();++i)
		if(s[i])
			printf("%c",s[i]);
    return 0;
}
