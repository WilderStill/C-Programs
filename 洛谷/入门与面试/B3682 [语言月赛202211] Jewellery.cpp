#include <bits/stdc++.h>
using namespace std;
map<string,int> mp,c;
int n,k,ans;
string s;
int main()
{
    cin>>n>>k;
    for(int i=1,a;i<=n;i++)
    {
    	cin>>s>>a;
    	c[s]=0;
    	if(a==1)mp[s]=2000;
    	else if(a==2)mp[s]=1000;
    	else if(a==3)mp[s]=200;
    	else if(a==4)mp[s]=36;
    	else mp[s]=6;
	}
	for(int i=1;i<=k;i++)
    {
    	cin>>s;
    	if(!c[s])c[s]++;
    	else ans+=mp[s];
	}
	cout<<ans;
    return 0;
}
