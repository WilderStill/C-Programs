#include<bits/stdc++.h>
using namespace std;
string s1,s2;
unordered_map<string,int>mp;
int cases=0;
int main()
{
	while(cin>>s1>>s2)
	{
		if(cases)puts("");
		mp.clear();
		int t1=s1.size(),t2=s2.size(),len=0;
		for(int l=1;l<=t1;++l)for(int i=0;i<=t1-l;++i)mp[s1.substr(i,l)]|=1;
		for(int l=1;l<=t2;++l)for(int i=0;i<=t2-l;++i)mp[s2.substr(i,l)]|=2;
        for(auto s:mp)if(s.second==3)len=max(len,(int)s.first.size()); 
		if(!len)puts("No common sequence.");
		else
		{
			vector<string>ans;
			for(auto s:mp)if(s.second==3&&(int)s.first.size()==len)ans.emplace_back(s.first);
			sort(ans.begin(),ans.end());
			for(auto s:ans)cout<<s<<endl;
		}
		++cases;
	}
	return 0;
}
