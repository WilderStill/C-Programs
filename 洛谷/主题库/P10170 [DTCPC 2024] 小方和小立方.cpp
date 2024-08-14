#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int vis[30],n,ans;
int main()
{
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		vis[s[i]-'a']=1;
		ans++;
		for(int j=1;j<=i&&j<=s.length()-i;j++)
		{
			if((s[i-j]!=s[i+j])||(vis[s[i-j]-'a']>=1))break;
			ans++;
			vis[s[i-j]-'a']+=2;
		}
		for(int k=0;k<=26;k++)vis[k]=0;
	}
	for(int i=0;i<s.length()-1;i++)
	{
		if(s[i]!=s[i+1])continue;
		ans++;
		vis[s[i]-'a']=2;
		for(int j=1;j<=i&&j<=s.length()-i-1;j++)
		{
			if((s[i-j]!=s[i+j+1])||(vis[s[i-j]-'a']>=1))break;
			ans++;
			vis[s[i-j]-'a']+=2;
		}
		for(int k=0;k<=26;k++)vis[k]=0;
	}
	printf("%lld",ans);
	return 0;
}
