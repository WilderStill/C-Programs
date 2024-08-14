#include<bits/stdc++.h>
using namespace std;
string s[20];
int len=0,n,vis[20];
int con(string s1,string s2)
{
	int len1=s1.size(),len2=s2.size();
	for(int i=1;i<min(len1,len2);++i)
	{
		bool fg=1;
		for(int j=0;j<i;++j)
			if(s1[len1-i+j]!=s2[j]){fg=0;break;}
		if(fg)return i;
	}
	return 0;
}
void dfs(string sn,int lenn)
{
	len=max(lenn,len);
	for(int i=0;i<n;++i)
	{
		if(vis[i]>1)continue;
		int pos=con(sn,s[i]);
		if(pos)
		{
			++vis[i];
			dfs(s[i],s[i].size()+lenn-pos);
			--vis[i];
		}
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<=n;++i)cin>>s[i]; 
	dfs(' '+s[n],1);
	cout<<len;
	return 0;
}
