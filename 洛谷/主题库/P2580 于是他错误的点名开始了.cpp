#include<bits/stdc++.h>
using namespace std;
map<string,string>mp;
string s;
int n,m;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
	{
    	cin>>s;
		mp[s]="dontwannacry";
    }
    scanf("%d",&m);
    for(int i=1;i<=m;++i)
	{
    	cin>>s;
    	if(mp[s]=="dontwannacry")
		{
			puts("OK");
			mp[s]="Jadonyzx";
		}
    	else if(mp[s]=="Jadonyzx")puts("REPEAT");
    	else puts("WRONG");
    }
	return 0;
}
